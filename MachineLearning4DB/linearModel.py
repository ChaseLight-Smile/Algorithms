
# 方法一：使用pytorch实现线性模型，线性模型可以看成只有一个神经元的神经网络
import torch
# 1. 准备数据
x_data = torch.Tensor([[1.0], [2.0], [3.0]])
y_data = torch.Tensor([[2.0], [4.0], [6.0]])

# 2. 构建模型
class LinearModel(torch.nn.Module):
    def __init__(self):
        super(LinearModel, self).__init__()
        self.linear = torch.nn.Linear(1, 1)
    def forward(self, x):
        y_pred = self.linear(x)
        return y_pred
    # 在该类中隐含实现了__call__回调函数

model = LinearModel()

# 3. 构建损失函数和优化器
loss = torch.nn.MSELoss(reduction='sum')
optimizer = torch.optim.SGD(model.parameters(), lr=0.01)

# 4. 训练结果
if __name__ == "__main__":
    for epoch in range(1000):
        y_pred = model(x_data)  # callable对象，model(x)调用将会传递给LinearModel的__call__()，而__call__会调用forward(self, x)函数
        lo = loss(y_pred, y_data)
        print(epoch, lo.item())

        optimizer.zero_grad() # 梯度归零
        lo.backward() #反向传播，计算loss对参数的偏导数
        optimizer.step()  # 更新所有参数、梯度、学习率等的信息
    # 输出权重和bias
    print('w = ', model.linear.weight.item())
    print('b = ', model.linear.bias.item())

    # 测试模型
    x_test = torch.Tensor([[4.0]]) #当输入为4时
    y_test = model(x_test)  # 从模型中计算输出
    print('y_pred = ', y_test.data)
