"""
numpy实现两层神经网络，其中包含一个全连接ReLU神经网络，一个隐藏层，没有bias，用来从x预测y
使用L2 loss
* $h = W_1 * x$
* $a = ReLU(0, h)$
* $y_hat = W_2 * a$
这一实现完全使用numpy来计算前向神经网络，loss和反向传播
numpy中的ndarray是一个普通的n维array，它知道任何关于深度学习或者梯度（gradient）的知识，
也不知道计算图（computation graph），只是一种用来计算数学运算的数据结构。
* foward pass
* loss
* backward pass求梯度，并更新参数
"""

import numpy as np
iter_time = 1000 # 表示学习次数
#N表示只有64个训练数据，1000表示输入的维度， 100是中间层维度，10是输出维度,将1000维向量转成10维
N, D_in, H, D_out = 64, 1000, 100, 10

# 随机创建一些训练数据
x = np.random.randn(N, D_in)
print(x)
y = np.random.randn(N, D_out)

w1 = np.random.randn(D_in, H)
w2 = np.random.randn(H, D_out)

learning_rate = 1e-6
for t in range(iter_time):
  # forward pass
  h = x.dot(w1)   #N*H的向量
  h_relu = np.maximum(0, h) # N*H
  y_pred = h_relu.dot(w2)  # N*D_out
  
  # computing loss
  loss = np.square(y_pred - y).sum()
  print(t, loss)
  
  # backward pass
  # computing gradient
  grad_y_pred = 2.0 * (y_pred - y)
  grad_w2 = h_relu.T.dot(grad_y_pred) # h_relu是N*H, grad_y_pred是N*D_out乘法需要转置
  grad_h_relu = grad_y_pred.dot(w2.T)
  grad_h = grad_h_relu.copy()
  grad_h[h < 0] = 0
  grad_w1 = x.T.dot(grad_h)

  #update weights of w1 and w2
  w1 -= learning_rate * grad_w1
  w2 -= learning_rate * grad_w2
