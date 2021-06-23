# 从边缘检测的例子中，我们可以得到，Conv kernel实际是可以学习的参数
import torch
def corr2d(X, K):
  h, w = K.shape
  Y = torch.zeros(X.shape[0]-h+1, X.shape[1]-w+1)
  for i in range(Y.shape[0]):
    for j in range(Y.shape[1]):
      Y[i, j] = (X[i:i+h, j:j+w]*K).sum()
  return Y

X = torch.ones((6, 8))
X[:, 2:6] = 0
K1 = torch.tensor([[1.0], [-1.0]])   # 2行1列的二维tensor，检测水平的边缘

Y1= corr2d(X.T, K1)
print(Y1)

K2 = torch.tensor([[1.0, -1.0]])  # 1行2列的二维tensor，检测垂直的边缘
Y2 = corr2d(X, K2)
print(Y2)