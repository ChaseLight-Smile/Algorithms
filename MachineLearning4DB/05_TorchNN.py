import torch.nn
iter_time = 1000
N, D_in, H, D_out = 64, 1000, 100, 10
x = torch.randn(N, D_in)
y = torch.randn(N, D_out)
model = torch.nn.Sequential(
    torch.nn.Linear(D_in, H),   # 输入层和输出层之间都能设置bias = False
    torch.nn.ReLU(),
    torch.nn.Linear(H, D_out),
)
# model = model.cuda()
torch.nn.init.normal_(model[0].weight)   # model[0]表示第一层，model[0].weight表示第1层的weight满足正态分布
torch.nn.init.normal_(model[2].weight)   # model[2]表示第一层，model[2].weight表示第2层层的weight满足正态分布
torch.nn.init.normal_(model[0].bias)
torch.nn.init.normal_(model[2].bias)

loss_fn = torch.nn.MSELoss(reduction = 'sum')
learning_rate = 1e-6
for t in range(iter_time):
  y_pred = model(x)
  loss = loss_fn(y_pred, y)
  print(t, loss.item())
  model.zero_grad()
  # computing grad
  loss.backward()

  with torch.no_grad():
    for param in model.parameters():
      param -= learning_rate * param.grad
