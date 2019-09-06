#针对无向图，有向图，多重图实现Forest Fire抽样算法
import random
import networkx as nx
import matplotlib.pyplot as plt
import time

def read_txt_to_undirected_graph(filename):
    file = open(filename, 'r')
    G = nx.Graph()
    for line in file.readlines():
        node = line.split()
        G.add_edge(int(node[0]),int(node[1]))
    # tmp = filename.split('.')
    # output_file = tmp[0] + "undiredted." + tmp[1]
    # nx.write_gml(G, output_file)
    return G

# G : Original Graph
# size : size of the sampled graph
class ForestFire():
    def __init__(self):
        self.G1 = nx.Graph()

    def forestfire(self,G,size):
        list_nodes=list(G.nodes())
        #print(len(G))
        dictt = set()
        random_node = random.sample(set(list_nodes),1)[0]
        #print(random_node)
        q = set() #q = set contains the distinct values
        q.add(random_node)
        while(len(self.G1.nodes())<size):
            if(len(q)>0):
                initial_node = q.pop()
                if(initial_node not in dictt):
                    #print(initial_node)
                    dictt.add(initial_node)
                    neighbours = list(G.neighbors(initial_node))
                    if (len(neighbours) == 0):   #这个判断主要是针对在有向图中，如果没有邻居点存在时，此时应该重新从点列表中选择一个新的点，继续while循环。
                        random_node = random.sample(set(list_nodes) and dictt,1)[0]
                        q.add(random_node)
                        continue
                    #print(list(G.neighbors(initial_node)))
                    np = random.randint(1,len(neighbours))
                    #print(np)
                    #print(neighbours[:np])
                    for x in neighbours[:np]:
                        if(len(self.G1.nodes())<size):
                            self.G1.add_edge(initial_node,x)
                            q.add(x)
                        else:
                            break
                else:
                    continue
            else:
                random_node = random.sample(set(list_nodes) and dictt,1)[0]
                q.add(random_node)
        q.clear()
        return self.G1



if __name__ == "__main__":
    file = input("please input file path and name:")
    g = read_txt_to_undirected_graph(file)
    # g = nx.read_edgelist("fb.txt", create_using= nx.Graph(),nodetype=int)
    print("number of nodes:", g.number_of_nodes())
    print("number of edges:", g.number_of_edges())
    print("---------------------------------------------This is sepration line!---------------------------------------------")
   # make an object and call function FF
    object4=ForestFire()
    sample4 = object4.forestfire(g,28000) # graph, number of nodes to sample
    print("Forest Fire Sampling")
    print("Number of nodes sampled=",len(sample4.nodes()))
    print("Number of edges sampled=",len(sample4.edges()))

    print("---------------------------------------------This is sepration line!---------------------------------------------")
    #通过导出子图步骤得到连通性更好的图
    induced_graph = g.subgraph(sample4.nodes())
    print("Induced Forest Fire Sampling")
    print("Number of nodes sampled=",len(induced_graph.nodes()))
    print("Number of edges sampled=",len(induced_graph.edges()))
