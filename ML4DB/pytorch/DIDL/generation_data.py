import torch
import random

def synthetic_data(w, b, num_examples): 

    X = torch.normal(0, 1, (num_examples, len(w)))
    y = torch.mv(X, w).reshape((-1,1))+ b  # 对b做了broadcast.得到一个一维的tensor
    y += torch.normal(0, 0.01,  (num_examples, 1))
    return X, y

true_w = torch.tensor([2, -3.4])
true_w.reshape((-1,1))
true_b = torch.zeros((1000,1))   # b写成了1000*1的二维tensor
true_b[:] = 4.2
features, labels = synthetic_data(true_w, true_b, 1000)



def synthetic_data(w, b, num_examples): 
    X = torch.normal(0, 1, (num_examples, len(w)))
    y = torch.matmul(X, w) + b
    y += torch.normal(0, 0.01, y.shape)
    return X, y.reshape((-1, 1))

true_w = torch.tensor([2, -3.4])
true_b = 4.2
features, labels = synthetic_data(true_w, true_b, 1000)