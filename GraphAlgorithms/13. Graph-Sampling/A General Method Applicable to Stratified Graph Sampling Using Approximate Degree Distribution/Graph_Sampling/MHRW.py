import random
import networkx as nx
import matplotlib.pyplot as plt

def read_txt_to_undirected_graph(filename):
    file = open(filename, 'r')
    G = nx.DiGraph()
    for line in file.readlines():
        node = line.split()
        G.add_edge(int(node[0]),int(node[1]))
    # tmp = filename.split('.')
    # output_file = tmp[0] + "undiredted." + tmp[1]
    # nx.write_gml(G, output_file)
    return G

class MHRW():
    def __init__(self):
        self.G1 = nx.DiGraph()

    def mhrw(self,G,node,size):
        dictt = {}
        node_list = set()
        node_list.add(node)
        parent_node = node_list.pop()
        dictt[parent_node] = parent_node
        degree_p = G.degree(parent_node)
        related_list = list(G.neighbors(parent_node))
        node_list.update(related_list)

        while(len(self.G1.nodes()) <= size):
            if(len(node_list) > 0):
                child_node = node_list.pop()
                p =  round(random.uniform(0,1),4)
                if(child_node not in dictt):
                    related_listt = list(G.neighbors(child_node))
                    degree_c = G.degree(child_node)
                    dictt[child_node] = child_node
                    if(p <= min(1,degree_p/degree_c) and child_node in list(G.neighbors(parent_node))):
                        self.G1.add_edge(parent_node,child_node)
                        parent_node = child_node
                        degree_p = degree_c
                        node_list.clear()
                        node_list.update(related_listt)
                    else:
                        del dictt[child_node]


            # node_list set becomes empty or size is not reached 
            # insert some random nodes into the set for next processing
            else:
                node_list.update(random.sample(set(G.nodes())-set(self.G1.nodes()),3))
                parent_node = node_list.pop()
                G.add_node(parent_node)
                related_list = list(G.neighbors(parent_node))
                node_list.clear()
                node_list.update(related_list)
        return self.G1


if __name__ == "__main__":
    file = input("please input file path and name:")
    g = read_txt_to_undirected_graph(file)
    # g = nx.read_edgelist("fb.txt", create_using= nx.Graph(),nodetype=int)
    # print(g.number_of_nodes())

    # make an object and call function MHRW
    object5=MHRW()
    sample5 = object5.mhrw(g,28000,100) # original graph, number of nodes to sample, 100表示样本中抽取点的个数
    nx.draw(sample5)
    plt.show()
    print("Metropolis Hasting Random Walk Sampling:")
    print("Number of nodes sampled=",len(sample5.nodes()))
    print("Number of edges sampled=",len(sample5.edges()))

    print("---------------------------------------------This is sepration line!---------------------------------------------")
    #利用导出子图技术，增加图的连通性，使得抽样结果更好
    induced_graph = g.subgraph(sample5.nodes())
    nx.draw(induced_graph)
    plt.show()
    print("Induced Metropolis Hasting Random Walk Sampling:")
    print("Number of nodes sampled=",len(induced_graph.nodes()))
    print("Number of edges sampled=",len(induced_graph.edges()))
