import torch
from torch import nn
from d2l import torch as d2l

class Reshape(torch.nn.Module):
    def forward(self, x):
        return x.view(-1, 1, 28, 28)

net = torch.nn.Sequential(Reshape(), nn.Conv2d(1, 6, kernel_size=5,
                                               padding=2), nn.Sigmoid(),
                          nn.AvgPool2d(kernel_size=2, stride=2),
                          nn.Conv2d(6, 16, kernel_size=5), nn.Sigmoid(),
                          nn.AvgPool2d(kernel_size=2, stride=2), nn.Flatten(),
                          nn.Linear(16 * 5 * 5, 120), nn.Sigmoid(),
                          nn.Linear(120, 84), nn.Sigmoid(), nn.Linear(84, 10))

net[1].weight.data.normal_(0, 0.01)
net[1].bias.data.fill_(0)  # 一维的len  = 6的tensor

net[4].weight.data.normal_(0, 0.01) 
net[4].bias.data.fill_(0) # 一维的长度为16的tensor

# 导入数据
batch_size = 256
train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size=batch_size)

# device = torch.device('cuda' if torch.cuda.is_available else 'cpu') 
# net = net.to(device)  # CNN在GPU上
num_epochs = 5
lr = 0.001
optimizer = torch.optim.SGD(net.parameters(), lr=lr)
loss = nn.CrossEntropyLoss()

for epoch in range(num_epochs):
      net.train()  # pytorch 规范，train()在pytorch自带的函数
      for i, (X, y) in enumerate(train_iter, 1):
          optimizer.zero_grad()  # 防止梯度累加
          # X, y = X.to(device), y.to(device)  #将数据放到GPU上
          y_hat = net(X)  #feed forward
          l = loss(y_hat, y)  # 计算loss
          l.backward()  #反向传播
          optimizer.step()   # 更新参数
