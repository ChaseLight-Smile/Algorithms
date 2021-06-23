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
# !pip uninstall torch torch-scatter torch-sparse torch-spline-conv torch-geometric
!pip install torch==1.7.1+cu110 torchvision==0.8.2+cu110  torchaudio===0.7.2 torchtext==0.8.1 -f https://download.pytorch.org/whl/torch_stable.html
!pip install torch-scatter -f https://pytorch-geometric.com/whl/torch-1.7.1+cu110.html
!pip install torch-sparse -f https://pytorch-geometric.com/whl/torch-1.7.1+cu110.html
!pip install torch-cluster -f https://pytorch-geometric.com/whl/torch-1.7.1+cu110.html
!pip install torch-spline-conv -f https://pytorch-geometric.com/whl/torch-1.7.1+cu110.html
!pip install torch-geometric 
!pip install tensorboardX
!wget https://bin.equinox.io/c/4VmDzA7iaHb/ngrok-stable-linux-amd64.zip
!unzip ngrok-stable-linux-amd64.zip
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

```shell
import torch
import torch.nn as nn
import torch.nn.functional as F

import torch_geometric.nn as pyg_nn
import torch_geometric.utils as pyg_utils

import time
from datetime import datetime

import networkx as nx
import numpy as np
import torch
import torch.optim as optim

from torch_geometric.datasets import TUDataset
from torch_geometric.datasets import Planetoid
from torch_geometric.data import DataLoader

import torch_geometric.transforms as T

from tensorboardX import SummaryWriter
from sklearn.manifold import TSNE
import matplotlib.pyplot as plt
```

