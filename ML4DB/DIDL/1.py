import torch 
import pandas as pd
import numpy as np
import os

# os.makedirs(os.path.join('..', 'data'), exist_ok=True)
# data_file = os.path.join('..', 'data', 'house_tiny.csv')

# with open(data_file, 'w') as f:
    # f.write('NumRooms,Alley,Price\n')  # 列名
    # f.write('NA,Pave,127500\n')  # 每行表示一个数据样本
    # f.write('2,NA,106000\n')
    # f.write('4,NA,178100\n')
    # f.write('NA,NA,140000\n')

# data = pd.read_csv(data_file)

# inputs = data.iloc[:, :2]
# outputs = data.iloc[:, -1]

# inputs = inputs.fillna(inputs.mean())
# print(inputs)

# inputs = pd.get_dummies(inputs, dummy_na=True)
# print(inputs)

# inputs = np.array(inputs)  # pandas object convet to numpy ndarray
# outputs = np.array(outputs)

# inputs = torch.tensor(inputs)
# outputs = torch.tensor(outputs)

# print(inputs)
# print(outputs)


os.makedirs(os.path.join('..', 'data'), exist_ok=True)   # 创建目录
data_file = os.path.join('..', 'data', 'house_tiny.csv')   # 得到inode

with open(data_file, 'w') as f:
    f.write('NumRooms,Alley,Price\n')  # 列名
    f.write('NA,Pave,127500\n')  # 每行表示一个数据样本
    f.write('2,NA,106000\n')
    f.write('4,NA,178100\n')
    f.write('NA,NA,140000\n')

data = pd.read_csv(data_file)
f.close()

inputs = data.iloc[:, :2]  # 取到前两列
outputs = data.iloc[:, -1]   # 取到第三列

inputs = inputs.fillna(inputs.mean())

inputs = pd.get_dummies(inputs, dummy_na=True)

print(type(inputs))
print(type(outputs))

inputs = np.array(inputs)  # pandas object convet to numpy ndarray
outputs = np.array(outputs)

inputs = torch.tensor(inputs)
outputs = torch.tensor(outputs)

print(inputs)
print(outputs)



