import random

def reservoir_sampling(reservoir, n):
    sampling_result = []
    for i in range(0,n):
        sampling_result.append(reservoir[i])
    t = n
    reservoir_size = len(reservoir)
    while (t < reservoir_size):
        r = int(reservoir[i]*random.random())
        if (r < n):
            sampling_result[r] = reservoir[t]
        t = t + 1
    return sampling_result

if __name__ == "__main__":
    reservoir = []
    for i in range(1,100):
        reservoir.append(i)
    print(reservoir)
    print(reservoir_sampling(reservoir,25))
