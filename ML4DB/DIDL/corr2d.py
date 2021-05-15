import torch
def corr2d(X, K):
  h, w = K.shape
  Y = torch.zeros(X.shape[0]-h+1, X.shape[1]-w+1)
  for i in range(Y.shape[0]):
    for j in range(Y.shape[1]):
      Y[i, j] = (X[i:i+h, j:j+w]*K).sum()
  return Y

X = torch.tensor([[0,1,2], [3,4,5], [6,7,8]])
K = torch.tensor([[0, 1], [2, 3]])   # 用该卷积核（filter）在输入数据X上做了一次卷积操作
Y = corr2d(X, K)
print(Y)