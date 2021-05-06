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

# 定义模型
num_inputs = 784
num_hiddens = 256
num_outputs = 10
net = nn.Sequential(nn.Flatten(), nn.Linear(784, 256), nn.ReLU(), nn.Linear(256, 10))

# 初始化参数
net[1].weight.data.normal_(0, 0.01)
net[1].bias.data.fill_(0)
net[3].weight.data.normal_(0, 0.01)
net[3].bias.data.fill_(0)

# 定义loss
loss = nn.CrossEntropyLoss()

# 定义优化器
optim = torch.optim.SGD(net.parameters(), lr = 0.1)

# 定义accuracy
def accuracy(y_hat, y):
    if len(y_hat.shape) > 1 and y_hat.shape[1] > 1:
        y_hat = y_hat.argmax(axis=1)  # 1维的包含n个（n为样本总数）分量的tensor
    cmp = y_hat.type(y.dtype) == y  # 1维的包含n个分量的tensor，并且每个分量的值都为True或者False
    return float(cmp.type(y.dtype).sum())  # 在这里实际上需要将True和False转成对应的1和0，因此，我们执行cmp.type(y.dtype)，将True或者false转成1或者0


num_epochs = 10
# 训练
acc = 0
for epoch in range(num_epochs):
  for X, y in train_iter:
    y_hat = net(X)
    l = loss(y_hat, y)
    optim.zero_grad()
    l.backward()
    optim.step()
    acc += accuracy(y_hat, y)
    # print(W)
    # print(b)
print(acc / 6000) 
acc = 0.0

for epoch in range(num_epochs):
  for X, y in test_iter:
    y_hat = net(X)
    acc += accuracy(y_hat, y)

print(acc / 1000) 