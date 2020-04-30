import random
import networkx as nx
import matplotlib.pyplot as plt
import math
import time
import csv
from datetime import datetime

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


class TIES():
    def __init__(self):
        self.G1 = nx.DiGraph()

    def ties(self,G,size,phi):
        V = G.nodes()																	
        #Calculate number of nodes in Graph G
        Vs = []																			
        #Empty list Vs														
        phi = round((phi * 0.01), 2)
        while (len(Vs)) <= math.floor(phi * len(V)):									
        #Loops run till sample size * length of V where V is number of nodes in graph as calculated above.
            edges_sample = random.sample(G.edges(), 1)									
            #Randomly samples one edge from a graph at a time
            for a1, a2 in edges_sample:													
            #Nodes corresponding to sample edge are retrieved and added in Graph G1
                self.G1.add_edge(a1, a2)
                if (a1 not in Vs):
                    Vs.append(a1)
                if (a2 not in Vs):
                    Vs.append(a2)															
        #Statement written just to have a check of a program
        
        for x in self.G1.nodes():
            neigh = (set(self.G1.nodes()) & set(list(G.neighbors(x))))						
            #Check neighbours of sample node and if the nodes are their in sampled set then edge is included between them.				
            for y in neigh:																
            #Check for every node's neighbour in sample set of nodes
                self.G1.add_edge(x, y)														
                #Add edge between the sampled nodes
        return self.G1

if __name__ == "__main__":
    file = input("please input file path and name:")
    g = read_txt_to_undirected_graph(file)
    print("number of nodes:", g.number_of_nodes())
    print("number of edges:", g.number_of_edges())
    print("---------------------------------------------This is sepration line!---------------------------------------------")

    object6=TIES()
    sample6 = object6.ties(g,10,1) # graph, number of nodes to sample, phi
    print("TIES:")
    print("Number of nodes sampled=",len(sample6.nodes()))
    print("Number of edges sampled=",len(sample6.edges()))

    print("---------------------------------------------This is sepration line!---------------------------------------------")
    incuded_graph = g.subgraph(sample6.nodes())
    print("Induced TIES:")
    print("Number of nodes sampled=",len(incuded_graph.nodes()))
    print("Number of edges sampled=",len(incuded_graph.edges()))
