import numpy as np
import torch

def early_stopping(log_value, best_value, stopping_step, flag_step, expected_order='asc'):
    assert expected_order in ['asc', 'des']
    if (expected_order == 'asc' and log_value >= best_value) or (expected_order == 'des' and log_value <= best_value):
        stopping_step = 0
        best_value = log_value
    else:
        stopping_step += 1

    if stopping_step >= flag_step:
        print("Early stopping at step: {} log:{}".format(flag_step, log_value))
        should_stop = True
    else:
        should_stop = False

    return best_value, stopping_step, should_stop

def train(model, data_generator, optimizer):
    model.train()
    n_batch = data_generator.n_train // data_generator.batch_size + 1
    running_loss=0
    for _ in range(n_batch):
        u, i, j = data_generator.sample()
        u, i, j = torch.tensor(u), torch.tensor(i), torch.tensor(j)
        optimizer.zero_grad()
        loss, u_g_embeddings, i_g_embeddings = model(u,i,j)
        loss = loss.mean()
        loss.backward()
        optimizer.step()
        running_loss += loss.item()
    model.module.u_g_embeddings = u_g_embeddings
    model.module.i_g_embeddings = i_g_embeddings
    return running_loss

def split_matrix(X, n_splits=100):
    splits = []
    chunk_size = X.shape[0] // n_splits
    for i in range(n_splits):
        start = i * chunk_size
        end = X.shape[0] if i == n_splits - 1 else (i + 1) * chunk_size
        splits.append(X[start:end])
    return splits

def compute_ndcg_k(pred_items, test_items, test_indices, k):
    r = (test_items * pred_items).gather(1, test_indices)
    f = torch.from_numpy(np.log2(np.arange(2, k+2))).float().cuda()   #如果显存爆炸，将.cuda()去掉，放在内存中计算
    dcg = (r[:, :k]/f).sum(1)
    dcg_max = (torch.sort(r, dim=1, descending=True)[0][:, :k]/f).sum(1)
    ndcg = dcg/dcg_max
    ndcg[torch.isnan(ndcg)] = 0
    return ndcg


def eval_model(u_emb, i_emb, Rtr, Rte, k):
    # split matrices
    ue_splits = split_matrix(u_emb)
    tr_splits = split_matrix(Rtr)
    te_splits = split_matrix(Rte)

    recall_k, ndcg_k= [], []
    # compute results for split matrices
    for ue_f, tr_f, te_f in zip(ue_splits, tr_splits, te_splits):

        scores = torch.mm(ue_f, i_emb.t())
        # scores = scores.to('cpu')   # 将数据放在内存中计算
        test_items = torch.from_numpy(te_f.todense()).float().cuda()  #如果显存爆炸，将.cuda()去掉，放在内存中计算
        non_train_items = torch.from_numpy(1-(tr_f.todense())).float().cuda() #如果显存爆炸，将.cuda()去掉，放在内存中计算
        scores = scores * non_train_items
        
        _, test_indices = torch.topk(scores, dim=1, k=k)
        pred_items = torch.zeros_like(scores).float()
        pred_items.scatter_(dim=1,index=test_indices,src=torch.tensor(1.0).cuda()) #如果显存爆炸，将.cuda()去掉，放在内存中计算

        topk_preds = torch.zeros_like(scores).float()
        topk_preds.scatter_(dim=1,index=test_indices[:, :k],src=torch.tensor(1.0))

        TP = (test_items * topk_preds).sum(1)
        rec = TP/test_items.sum(1)
        ndcg = compute_ndcg_k(pred_items, test_items, test_indices, k)

        recall_k.append(rec)
        ndcg_k.append(ndcg)

    return torch.cat(recall_k).mean(), torch.cat(ndcg_k).mean()
