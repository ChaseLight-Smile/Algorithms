import torch
iter_time = 500 # 表示学习次数
#N表示只有64个训练数据，1000表示输入的维度， 100是中间层维度，10是输出维度,将1000维向量转成10>维
N, D_in, H, D_out = 64, 1000, 100, 10

# 随机创建一些训练数据
x = torch.randn(N, D_in)
print(x)
y = torch.randn(N, D_out)

w1 = torch.randn(D_in, H, requires_grad = True)
w2 = torch.randn(H, D_out, requires_grad = True)

learning_rate = 1e-6
for t in range(iter_time):
  # forward pass
  h = x.mm(w1)   #N*H的向量
  h_relu = h.clamp(min = 0) # N*H
  y_pred = h_relu.mm(w2)  # N*D_out

  # computing loss
  loss = (y_pred - y).pow(2).sum()   #item要转成数字，否则是tensor，这里是computation graph，也是pytorch的核心
  print(t, loss.item())

  # backward pass
  # computing gradient
  loss.backward()

  #update weights of w1 and w2
  with torch.no_grad():   #不让计算图占内存，很产生很奇怪的效果，记住就好了
    w1 -= learning_rate * w1.grad #结果为计算图
    w2 -= learning_rate * w2.grad      
    w1.grad.zero_()
    w2.grad.zero_()

