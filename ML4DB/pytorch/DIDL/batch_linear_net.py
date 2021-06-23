import torch
import random

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

# 读取数据
# https://blog.csdn.net/mieleizhi0522/article/details/82142856
def data_iter(batch_size, features, labels):
  num_examples = len(features)
  indices = list(range(num_examples))
  random.shuffle(indices)   # 在这里必须要做一次shuffle，保证每个epoch中的每一个batch得到的数据都是不同的
  for i in range(0, num_examples, batch_size):
    batch_indices = torch.tensor(indices[i:min(i+batch_size, num_examples)])
    yield features[batch_indices], labels[batch_indices]

# 初始化参数
# w = torch.normal(0, 0.01, size=(2, 1), requires_grad=True)   # 2 * 1矩阵
w = torch.zeros(size=(2, 1), requires_grad=True) 
b = torch.ones(1, requires_grad=True)   # b只能是一个一维且长度为1的tensor

# 建立模型
def linreg(X, w, b):
  return torch.matmul(X, w).reshape(-1,1) + b

# 定义loss
def squared_loss(y_hat, y):
  return (y_hat - y) ** 2 / 2

# 定义优化器
def sgd(params, lr):
  with torch.no_grad():
    for param in params:
            param -= lr * param.grad / batch_size   # 如果这里不除以batch_size，在计算loss的地方应该除以batch_size，否则loss过大，在更新时会出现NaN错误
            param.grad.zero_()  # 防止叠加梯度信息


lr = 0.03
num_epochs = 5
net = linreg
loss = squared_loss
for epoch in range(num_epochs):
  for X, y in data_iter(batch_size, features, labels):
      l = loss(net(X, w, b), y).sum() # loss(net(X, w, b), y) 返回一个batch_size * 1 矩阵
      l.backward()
      sgd([w, b], lr)  # 使用参数的梯度更新参数
  with torch.no_grad():  # 在整体数据集上评估当前w和b得到的loss，求出所有样本的平均值
      train_l = loss(net(features, w, b), labels)
      print(f'epoch {epoch + 1}, loss {float(train_l.mean()):f}')
  print(w)
  print(b)