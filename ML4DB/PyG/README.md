# google colab安装pytorch geometric



## 环境准备

```shell
import torch 
print(torch.__version__)
print(torch.version.cuda)
!nvcc --version
!python --version
!pip --version  # 请注意将pip版本升级到20以上，google colab自带的版本为20以下，20以下后续安装PyG之后，在测试阶段不能使用，这主要是因为版本不兼容
!python -m pip install --upgrade pip   
```



## 安装pytorch geometric

```shell
!pip install torch==1.7.1+cu110 torchvision==0.8.2+cu110  torchaudio===0.7.2 -f https://download.pytorch.org/whl/torch_stable.html
!pip install torch-scatter -f https://pytorch-geometric.com/whl/torch-1.7.1+cu110.html
!pip install torch-sparse -f https://pytorch-geometric.com/whl/torch-1.7.1+cu110.html
!pip install torch-cluster -f https://pytorch-geometric.com/whl/torch-1.7.1+cu110.html
!pip install torch-spline-conv -f https://pytorch-geometric.com/whl/torch-1.7.1+cu110.html
!pip install torch-geometric 
```

或者使用下列脚本安装

```python
import torch

def format_pytorch_version(version):
  return version.split('+')[0]

TORCH_version = torch.__version__
TORCH = format_pytorch_version(TORCH_version)

def format_cuda_version(version):
  return 'cu' + version.replace('.', '')

CUDA_version = torch.version.cuda
CUDA = format_cuda_version(CUDA_version)

!pip install torch-scatter     -f https://pytorch-geometric.com/whl/torch-{TORCH}+{CUDA}.html
!pip install torch-sparse      -f https://pytorch-geometric.com/whl/torch-{TORCH}+{CUDA}.html
!pip install torch-cluster     -f https://pytorch-geometric.com/whl/torch-{TORCH}+{CUDA}.html
!pip install torch-spline-conv -f https://pytorch-geometric.com/whl/torch-{TORCH}+{CUDA}.html
```

## 测试

```python
import torch
import os
from torch_geometric.data import Data

edge_index = torch.tensor([[0, 1, 1, 2],
                           [1, 0, 2, 1]], dtype=torch.long)
x = torch.tensor([[-1], [0], [1]], dtype=torch.float)

data = Data(x=x, edge_index=edge_index)
print(data)
```

如果正确安装，输出为：

```shell
Data(edge_index=[2, 4], x=[3, 1])  # edge_index中，2代表边的数目为2, 4为边数目，因为是无向图，所以边有4条（分别是0-1， 1-0， 1-2， 2-1），x中的3表示有三个点，1表示每个点的num_node_feature = 1
```
