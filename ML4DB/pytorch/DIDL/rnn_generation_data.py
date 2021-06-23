import random
import torch
from d2l import torch as d2l

tokens = d2l.tokenize(d2l.read_time_machine())
# 因为每个文本行不一定是一个句子或一个段落，因此我们把所有文本行连接到一起
corpus = [token for line in tokens for token in line]
vocab = d2l.Vocab(corpus)
vocab.token_freqs[:10]

len(corpus), len(corpus[:-1]), len(corpus[1:])

bigram_tokens = []
for pair in zip(corpus[:-1], corpus[1:]):
  bigram_tokens.append(pair)
bigram_vocab = d2l.Vocab(bigram_tokens)
bigram_vocab.token_freqs[:10]

# def seq_data_iter_sequential(corpus, batch_size, num_steps):
#   offset = random.randint(0, num_steps)
#   num_tokens = ((len(corpus) - offset - 1) // batch_size) * batch_size
#   Xs = torch.tensor(corpus[offset:offset+num_tokens])
#   Ys = torch.tensor(corpus[offset+1:offset+1+num_tokens])

#   Xs = Xs.reshape(batch_size, -1)
#   Ys = Ys.reshape(batch_size, -1)
#   num_batches  = Xs.shape[1]//num_steps

#   for i in range(0, num_steps*num_batches, num_steps):
#     X = Xs[:,i: i+num_steps]
#     Y = Ys[:, i: i+num_steps]
#     yield X, Y

def seq_data_iter_random(corpus, batch_size, num_steps):
  offset = random.randint(0, num_steps-1)
  corpus = corpus[offset:]

  num_subseqs = (len(corpus) - 1) // num_steps

  indices = list(range(0, num_subseqs * num_steps, num_steps))
  random.shuffle(indices)
  num_batches = num_subseqs // batch_size
  def data(j):
    return corpus[j:j+num_steps]
  for i in range (0, num_batches * batch_size, batch_size):
    indices_per = indices[i:i+batch_size]
    X = [data(j) for j in indices_per]
    Y = [data(j+1) for j in indices_per]
    yield torch.tensor(X), torch.tensor(Y)
my_seq = list(range(35))
print(my_seq)
for X, Y in seq_data_iter_random(my_seq, batch_size=2, num_steps=5):
    print('X: ', X, '\nY:', Y)