import random
import torch
from torch import nn
from torch.utils import data


# 生成数据
def synthetic_data(w, b, num_examples): 
    X = torch.normal(0, 1, (num_examples, len(w)))
    y = torch.matmul(X, w).reshape((-1,1))+ b  # 对b做了broadcast.得到一个一维的tensor
    y += torch.normal(0, 0.01,  (num_examples, 1))
    return X, y
true_w = torch.tensor([2, -3.4])
true_w.reshape((-1,1))
true_b = 4.2
features, labels = synthetic_data(true_w, true_b, 1000) 


def load_data(data_arrays, batch_size, is_train):
  dataset = data.TensorDataset(*data_arrays)   # 把每一个sample封装成一个tensor
  return data.DataLoader(dataset, batch_size, shuffle=is_train)

batch_size = 10
data_iter = load_data((features, labels), batch_size, True)  # 得到了数据迭代器，每次调用都会取出batch_size大小的数据


# 定义模型
net = nn.Sequential(nn.Linear(2, 1))  # callrable

# 初始化模型参数
net[0].weight.data.normal_(0,0.01)  # 原地更新
net[0].bias.data.fill_(0)

# 定义loss
loss = nn.MSELoss()  # callable

# 定义优化算法
optim =  torch.optim.SGD(net.parameters(), lr=0.03)

# main函数
num_epochs = 3
for epoch in range(num_epochs):
  for X, y in data_iter:   #这个for中计算loss的步骤放到train方法中
    l = loss(net(X), y)
    optim.zero_grad()
    l.backward()
    # print(net[0].weight.grad)   # 权重的梯度信息
    optim.step()   # step()内置方法
  l = loss(net(features), labels)   #评估当前得到的w和b在全部训练数据集上的loss，其实我们应该把训练数据集拆分为train_data和validation_data，然后在validation_data也要算出其loss
  print(f'epoch {epoch + 1}, loss {l:f}')
  print(net[0].weight.data)
  print(net[0].bias.data)