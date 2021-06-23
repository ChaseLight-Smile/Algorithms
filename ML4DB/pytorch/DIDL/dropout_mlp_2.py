import torch
import torchvision
from torch.utils import data
from torchvision import transforms
from torch import nn

# 读取数据
def load_data_fashion_mnist(batch_size, resize=None):
    trans = [transforms.ToTensor()]
    if resize:
        trans.insert(0, transforms.Resize(resize))
    trans = transforms.Compose(trans)
    mnist_train = torchvision.datasets.FashionMNIST(root="../data",
                                                    train=True,
                                                    transform=trans,
                                                    download=True)
    mnist_test = torchvision.datasets.FashionMNIST(root="../data",
                                                   train=False,
                                                   transform=trans,
                                                   download=True)
    return (data.DataLoader(mnist_train, batch_size, shuffle=True),
            data.DataLoader(mnist_test, batch_size, shuffle=False))

# 获取数据
batch_size = 256
train_iter, test_iter = load_data_fashion_mnist(batch_size)

# 初始化参数
num_inputs = 784
num_outputs = 10
num_hidden = 256

W1 = torch.normal(0, 0.01, size=(num_inputs, num_hidden), requires_grad=True)
b1 = torch.zeros(num_hidden, requires_grad=True)
W2 = torch.normal(0, 0.01, size=(num_hidden, num_outputs), requires_grad = True)
b2 = torch.zeros(num_outputs, requires_grad=True)

# 定义激活函数
def relu(X):
  a = torch.zeros(1)  # 使用广播机制
  return torch.max(a, X)

# 定义dropout
def dropout_layer(X, dropouts):
  assert 0 <= dropouts <= 1
  if dropouts == 0:
    return X
  if dropouts == 1:
    return torch.zeros_like(X.shape)
  mask = (torch.Tensor(X.shape).normal_(0, 1) > dropouts).float()
  return mask * X / (1-dropouts)

# 定义模型
def mlp(X, is_train):
  X = X.reshape((-1, len(W1)))
  o = torch.matmul(X, W1) + b1
  if is_train:
     H = dropout_layer(o, 0.3)   # dropout应用在relu之前
     H = relu(H)
  else:
     H = relu(o)
  out = torch.matmul(H, W2)+b2
  return out

# 定义loss
loss = nn.CrossEntropyLoss()

# 定义优化器
def sgd(params, lr):
  with torch.no_grad():
    for param in params:
      param -= lr * param.grad
      param.grad.zero_()

# 定义accuracy
def accuracy(y_hat, y):
    if len(y_hat.shape) > 1 and y_hat.shape[1] > 1:
        y_hat = y_hat.argmax(axis=1)  # 1维的包含n个（n为样本总数）分量的tensor
    cmp = y_hat.type(y.dtype) == y  # 1维的包含n个分量的tensor，并且每个分量的值都为True或者False
    return float(cmp.type(y.dtype).sum())  # 在这里实际上需要将True和False转成对应的1和0，因此，我们执行cmp.type(y.dtype)，将True或者false转成1或者0


num_epochs = 10
lr = 0.1
# 训练
acc = 0
for epoch in range(num_epochs):
  for X, y in train_iter:
    y_hat = mlp(X, True)
    l = loss(y_hat, y)
    l.backward()
    sgd([W1, b1, W2, b2], lr)
    acc += accuracy(y_hat, y)
    # print(W)
    # print(b)
print(acc /6000) 
acc = 0.0

for epoch in range(num_epochs):
  for X, y in test_iter:
    y_hat = mlp(X,False)
    acc += accuracy(y_hat, y)

print(acc /1000) 