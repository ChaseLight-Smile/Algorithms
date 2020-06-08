import torch
iter_time = 1000 # 表示学习次数
#N表示只有64个训练数据，1000表示输入的维度， 100是中间层维度，10是输出维度,将1000维向量转成10>维
N, D_in, H, D_out = 64, 1000, 100, 10

# 随机创建一些训练数据
x = torch.randn(N, D_in)
print(x)
y = torch.randn(N, D_out)

w1 = torch.randn(D_in, H)
w2 = torch.randn(H, D_out)

learning_rate = 1e-6
for t in range(iter_time):
  # forward pass
  h = x.mm(w1)   #N*H的向量
  h_relu = h.clamp(min = 0) # N*H
  y_pred = h_relu.mm(w2)  # N*D_out

  # computing loss
  loss = (y_pred - y).pow(2).sum().item()   #item要转成数字，否则是tensor
  print(t, loss)

  # backward pass
  # computing gradient
  grad_y_pred = 2.0 * (y_pred - y)
  grad_w2 = h_relu.t().mm(grad_y_pred) # h_relu是N*H, grad_y_pred是N*D_out乘法需要转置
  grad_h_relu = grad_y_pred.mm(w2.t())
  grad_h = grad_h_relu.clone()
  grad_h[h < 0] = 0
  grad_w1 = x.t().mm(grad_h)

  #update weights of w1 and w2
  w1 -= learning_rate * grad_w1
  w2 -= learning_rate * grad_w2      
