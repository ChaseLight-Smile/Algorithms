import torch
import torchvision
from torch.utils import data

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
num_inputs = 784   # 1 * 28 * 28
num_outputs = 10
W = torch.normal(0, 0.01, size=(num_inputs, num_outputs), requires_grad=True)
b = torch.zeros(num_outputs, requires_grad=True)   # 初始化为一维的向量，其长度为num_outputs

# 定义模型
def softmax(X):
  X_exp = torch.exp(X)
  partition = X_exp.sum(1, keepdim=True)
  return X_exp / partition

def net(X):
  return softmax(torch.matmul(X.reshape((-1, len(W))), W) + b)

# 定义loss
# y 在这里就是代表[0,1,2,3,4,5,6,7,8,9]中选出的一个一维tensor
def cross_entropy(y_hat, y):  # h_hat (num_inputs * 10) 的tensor
  return -torch.log(y_hat[range(len(y_hat)), y])  # 没有求和

# 定义优化器
def sgd(params, lr):
  with torch.no_grad():
    for param in params:
            param -= lr * param.grad/batch_size
            param.grad.zero_()  # 防止叠加梯度信息

lr = 0.03
num_epochs = 3
# 训练
for epoch in range(num_epochs):
  for X, y in train_iter:
    y_hat = net(X)
    l = cross_entropy(y_hat, y) 
    l.sum().backward()
    sgd([W, b], lr)
    print(W)
    print(b)