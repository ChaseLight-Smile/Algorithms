import torch
from d2l import torch as d2l

def corr2d_multi_in(X, K):
    return sum(d2l.corr2d(x, k) for x, k in zip(X, K))

X = torch.tensor([[[0.0, 1.0, 2.0], [3.0, 4.0, 5.0], [6.0, 7.0, 8.0]],  # 输入有2到通道，每个通道都是一个3*3的矩阵
                  [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]])
K = torch.tensor([[[0.0, 1.0], [2.0, 3.0]], [[1.0, 2.0], [3.0, 4.0]]])  # 因为输入有两个通道，所以kernel隐含了包含2个通道，每个通道都是2*2的矩阵

def corr2d_multi_in_out(X, K):
    return torch.stack([corr2d_multi_in(X, k) for k in K], 0)

K = torch.stack((K, K + 1, K + 2), 0)   # 3个2通道的2*2矩阵
Y = corr2d_multi_in_out(X, K)  # 所以输出是3个 2*2矩阵
print(Y.shape)