import collections
import re
from d2l import torch as d2l

d2l.DATA_HUB['time_machine'] = (d2l.DATA_URL + 'timemachine.txt',
                                '090b5e7e70c295757f55df93cb0a180b9691891a')

def read_time_machine(): 
    with open(d2l.download('time_machine'), 'r') as f:
        lines = f.readlines()
    print(lines)
    results = []
    for line in lines:
      results.append(re.sub('[^A-Za-z]+', ' ', line).strip().lower())
    return results

lines = read_time_machine()
# print(f'# text lines: {len(lines)}')
# print(lines[0])
def tokenize(lines, token='word'):
    results = []
    if token == 'word':
        for line in lines:
          arr = line.split()
          results.append(arr)
        return results
    elif token == 'char':
        return [list(line) for line in lines]
    else:
        print('错误：未知令牌类型：' + token)

tokens = tokenize(lines)  # 二维list，list[i]都表示原来文本的一行
# tokens = tokenize(lines, 'char')  # 测试结果
# print(tokens)
# for i in range(11):
#     print(tokens[i])

class Vocab:  # 词汇表的目的就是生成一个hash table，每一个token都应该对应一个唯一的索引值 [token, index]
    """文本词表"""
    def __init__(self, tokens=None, min_freq=0, reserved_tokens=None):
        if tokens is None:
            tokens = []
        if reserved_tokens is None:
            reserved_tokens = []
        
        counter = count_corpus(tokens)
        # print(type(counter))
        # for key, value in counter.items():
        #   print(key, value)   # 打印counter.items()字典中的每个元素
        self.token_freqs = sorted(counter.items(), key=lambda x: x[1],
                                  reverse=True)   # 默认是升序，reverse=True为降序
        # print(type(self.token_freqs))  # 返回一个list对象
        # print(self.token_freqs)

        self.unk = 0
        self.idx_to_token = ['unk']
        self.token_to_idx =  dict()  # idx_to_token 为list类型 token_to_idx为dict类型
        self.token_to_idx['unk'] = 0
        for token, _ in self.token_freqs:
            self.idx_to_token.append(token)
            self.token_to_idx[token] = len(self.idx_to_token) - 1

    def __len__(self):
        return len(self.token_to_idx)

    def __getitem__(self, tokens):
        if not isinstance(tokens, (list, tuple, dict)):
            return self.token_to_idx.get(tokens, self.unk)   # 访问token_to_idx字典，如果key在字典中，则返回其对应的value，如果key不在，则返回self.unk标记
        return [self.__getitem__(token) for token in tokens]

    def to_tokens(self, indices):
        if not isinstance(indices, (list, tuple,dict)):
            return self.idx_to_token[indices]
        return [self.idx_to_token[index] for index in indices]

def count_corpus(tokens):
    # 这里的 `tokens` 是 1D 列表或 2D 列表
    if len(tokens) == 0 or isinstance(tokens[0], list):   # isinstance 就是判断tokens[0]是不是list类型
        # 将标记列表展平成使用标记填充的一个列表
        results = []
        for line in tokens:
          for t in line:
            results.append(t)
        tokens = results
    return collections.Counter(tokens)

vocab =Vocab(tokens)
# for i in [0, 10]:
#     print('words:', tokens[i])
#     print('indices:', vocab[tokens[i]])  # 这里默认调用__getitem__方法

def load_corpus_time_machine(max_tokens=-1):
    """返回时光机器数据集的标记索引列表和词汇表。"""
    lines = read_time_machine()
    tokens = tokenize(lines, 'char')  # 二维数组
    vocab = Vocab(tokens)
    # 因为时光机器数据集中的每一个文本行，不一定是一个句子或一个段落，
    # 所以将所有文本行展平到一个列表中
    # corpus = [vocab[token] for line in tokens for token in line]  # 把整个文本表示为一个一维index list
    corpus = []
    for line in tokens:
      for token in line:
        corpus.append(vocab[token])
    if max_tokens > 0:
        corpus = corpus[:max_tokens]
    return corpus, vocab

corpus, vocab = load_corpus_time_machine()
print(corpus)
len(corpus), len(vocab)