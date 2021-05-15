# 从边缘检测的例子中，我们可以得到，Conv kernel实际是可以学习的参数
import torch
import torch.nn as nn

def corr2d(X, K):
  Y = torch.zeros(X.shape[0]-h+1, X.shape[1]-w+1)
  for i in range(Y.shape[0]):
    for j in range(Y.shape[1]):
      Y[i, j] = (X[i:i+h, j:j+w]*K).sum()
  return Y

class Conv2DNet(nn.Module):
  def __init__(self, kernel_size):
    super(Conv2DNet, self).__init__()
    self.weight = nn.Parameter(torch.randn(kernel_size))   # 1维的tensor，len为kernel_size
    self.bias = nn.Parameter(torch.zeros(1))
  def forward(self, x):
    return corr2d(x,  self.weight) + self.bias

#定义了输入输出模块
X = torch.ones((6, 8))   
X[:, 2:6] = 0   # 输入
net = Conv2DNet((1,2))
K = torch.tensor([[1.0, -1.0]])
Y = corr2d(X, K)   # 输出

X = X.reshape((6, 8))
Y = Y.reshape((6, 7))  # 6 和 7 是通过公式计算出来的

def train(X):
  for i in range(100):
    Y_hat = net(X)
    loss = (Y_hat - Y) ** 2
    net.zero_grad()
    loss.sum().backward()
    net.weight.data[:] -= 0.003 * net.weight.grad
    net.bias.data[:] -= 0.003 * net.bias.grad
    if(i + 1)% 2 == 0:
      print(f'batch {i+1}, loss {loss.sum():.3f}')
train(X)
print(net.weight.data, net.bias.data)