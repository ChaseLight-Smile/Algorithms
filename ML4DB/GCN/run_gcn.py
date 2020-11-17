'''
>> python run_gcn.py --dataset test --emb_dim 64 --layers [64]
'''

import pandas as pd
import torch

import os
from time import time
from datetime import datetime

from utils.load_data import Data
from utils.parser import parse_args
from utils.helper_functions import early_stopping,\
                                   train,\
                                   split_matrix,\
                                   compute_ndcg_k,\
                                   eval_model
from gcn import GCN

device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

if __name__ == '__main__':

    # read parsed arguments
    args = parse_args()
    data_dir = args.data_dir
    dataset = args.dataset
    batch_size = args.batch_size
    layers = eval(args.layers)
    emb_dim = args.emb_dim
    lr = args.lr
    reg = args.reg
    mess_dropout = args.mess_dropout
    node_dropout = args.node_dropout
    k = args.k

    # generate the GCN-adjacency matrix
    data_generator = Data(path=data_dir + dataset, batch_size=batch_size)
    adj_mtx = data_generator.get_adj_mat()

    # create model name and save
    modelname =  "GCN" + \
        "_bs_" + str(batch_size) + \
        "_nemb_" + str(emb_dim) + \
        "_layers_" + str(layers) + \
        "_nodedr_" + str(node_dropout) + \
        "_messdr_" + str(mess_dropout) + \
        "_reg_" + str(reg) + \
        "_lr_"  + str(lr)

    # create GCN model
    model = GCN(data_generator.n_users, 
                 data_generator.n_items,
                 emb_dim,
                 layers,
                 reg,
                 node_dropout,
                 mess_dropout,
                 adj_mtx)
    model.to(device='cuda:0')
    model = torch.nn.DataParallel(model, device_ids=[0,1])
    # current best metric
    cur_best_metric = 0

    # Adam optimizer
    optimizer = torch.optim.Adam(model.parameters(), lr=args.lr)

    # Set values for early stopping
    cur_best_loss, stopping_step, should_stop = 1e3, 0, False
    today = datetime.now()

    print("Start at " + str(today))
    print("Using " + str(device) + " for computations")
    print("Params on CUDA: " + str(next(model.parameters()).is_cuda))

    results = {"Epoch": [],
               "Loss": [],
               "Recall": [],
               "NDCG": [],
               "Training Time": []}

    for epoch in range(args.n_epochs):

        t1 = time()
        loss = train(model, data_generator, optimizer)
        training_time = time()-t1
        print("Epoch: {}, Training time: {:.2f}s, Loss: {:.4f}".
            format(epoch, training_time, loss))

        # print test evaluation metrics every N epochs (provided by args.eval_N)
        if epoch % args.eval_N  == (args.eval_N - 1):
            with torch.no_grad():
                t2 = time()
                with torch.no_grad():
                    recall, ndcg = eval_model(model.module.u_g_embeddings.detach()[:data_generator.n_users],
                                          model.module.i_g_embeddings.detach()[:data_generator.n_items],
                                          data_generator.R_train,
                                          data_generator.R_test,
                                          k)
            print(
                "Evaluate current model:\n",
                "Epoch: {}, Validation time: {:.2f}s".format(epoch, time()-t2),"\n",
                "Loss: {:.4f}:".format(loss), "\n",
                "Recall@{}: {:.4f}".format(k, recall), "\n",
                "NDCG@{}: {:.4f}".format(k, ndcg)
                )

            cur_best_metric, stopping_step, should_stop = \
            early_stopping(recall, cur_best_metric, stopping_step, flag_step=5)

            # save results in dict
            results['Epoch'].append(epoch)
            results['Loss'].append(loss)
            results['Recall'].append(recall.item())
            results['NDCG'].append(ndcg.item())
            results['Training Time'].append(training_time)
        else:
            # save results in dict
            results['Epoch'].append(epoch)
            results['Loss'].append(loss)
            results['Recall'].append(None)
            results['NDCG'].append(None)
            results['Training Time'].append(training_time)

        if should_stop == True: break

    # save
    if args.save_results:
        date = today.strftime("%d%m%Y_%H%M")

        # save model as .pt file
        if os.path.isdir("./models"):
            torch.save(model.module.state_dict(), "./models/" + str(date) + "_" + modelname + "_" + dataset + ".pt")
        else:
            os.mkdir("./models")
            torch.save(model.module.state_dict(), "./models/" + str(date) + "_" + modelname + "_" + dataset + ".pt")

        # save results as pandas dataframe
        results_df = pd.DataFrame(results)
        results_df.set_index('Epoch', inplace=True)
        if os.path.isdir("./results"):
            results_df.to_csv("./results/" + str(date) + "_" + modelname + "_" + dataset + ".csv")
        else:
            os.mkdir("./results")
            results_df.to_csv("./results/" + str(date) + "_" + modelname + "_" + dataset + ".csv")
        # plot loss
        print("computing success!")
        #results_df['Loss'].plot(figsize=(12,8), title='Loss')
