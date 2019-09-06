import json
import sys
import random
import math 
import time
import networkx as nx
import matplotlib.pyplot as plt
from collections import defaultdict

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


class Queue():
    #Constructor creates a list
    def __init__(self):
        self.queue = list()
    
    #Adding elements to queue
    def enqueue(self,data):
        #Checking to avoid duplicate entry (not mandatory)
        if data not in self.queue:
            self.queue.insert(0,data)
            return True
        return False
    
    #Removing the last element from the queue
    def dequeue(self):
        if len(self.queue)>0:
            return self.queue.pop()
        else:
            #plt.show()
            exit()
    
    #Getting the size of the queue
    def size(self):
        return len(self.queue)
    
    #printing the elements of the queue
    def printQueue(self):
        return self.queue

class Snowball():

    def __init__(self):
        self.G1 = nx.DiGraph()

    def snowball(self,G,size,k):
        q=Queue() 
        list_nodes=list(G.nodes())
        m = k
        dictt = set()
        while(m):
            id = random.sample(list(G.nodes()),1)[0]
            q.enqueue(id)
            m = m - 1
        #print(q.printQueue())
        while(len(self.G1.nodes()) <= size):
            if(q.size() > 0):
                id = q.dequeue()
                self.G1.add_node(id)
                if(id not in dictt):
                    dictt.add(id)
                    list_neighbors = list(G.neighbors(id))
                    if(len(list_neighbors) > k):
                        for x in list_neighbors[:k]:
                            q.enqueue(x)
                            self.G1.add_edge(id,x)
                    elif(len(list_neighbors) <= k and len(list_neighbors) > 0):
                        for x in list_neighbors:
                            q.enqueue(x)
                            self.G1.add_edge(id,x)
                else:
                    continue
            else:
                initial_nodes = random.sample(list(G.nodes()) and list(dictt),k)
                no_of_nodes = len(initial_nodes)
                for id in initial_nodes:
                    q.enqueue(id) 
        return self.G1


if __name__ == "__main__":
    file = input("please input file path and name:")
    g = read_txt_to_undirected_graph(file)
    print("number of nodes:", g.number_of_nodes())
    print("number of edges:", g.number_of_edges())
    print("---------------------------------------------This is sepration line!---------------------------------------------")
    # g = nx.read_edgelist("fb.txt", create_using= nx.Graph(),nodetype=int)
    # make an object and call function SB
    object3=Snowball()
    sample3 = object3.snowball(g,28000,25) # graph, number of nodes to sample , k set
    print("Snowball Sampling:")
    print("Number of nodes sampled=",len(sample3.nodes()))
    print("Number of edges sampled=",len(sample3.edges()))

    print("---------------------------------------------This is sepration line!---------------------------------------------")

    induced_graph = g.subgraph(sample3.nodes())
    print("Induced Snowball Sampling:")
    print("Number of nodes sampled=",len(induced_graph.nodes()))
    print("Number of edges sampled=",len(induced_graph.edges()))
