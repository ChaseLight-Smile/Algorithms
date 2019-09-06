# The three algorithms realize directed graphs and undirected graphs
import random
import time
import datetime
import io
import array,re,itertools
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
from itertools import groupby

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


class SRW_RWF_ISRW:

    def __init__(self):
        self.growth_size = 2
        self.T = 100 #number of iterations
        #with a probability (1-fly_back_prob) select a neighbor node
        #with a probability fly_back_prob go back to the initial vertex
        self.fly_back_prob = 0.15

    def random_walk_sampling_simple(self,complete_graph, nodes_to_sample):
        complete_graph = nx.convert_node_labels_to_integers(complete_graph, 0, 'default', True)
        # giving unique id to every node same as built-in function id
        for n, data in complete_graph.nodes(data=True):
            complete_graph.node[n]['id'] = n

        nr_nodes = len(complete_graph.nodes())
        upper_bound_nr_nodes_to_sample = nodes_to_sample
        index_of_first_random_node = random.randint(0, nr_nodes-1)
        sampled_graph = nx.Graph()

        sampled_graph.add_node(complete_graph.node[index_of_first_random_node]['id'])

        iteration = 1
        edges_before_t_iter = 0
        curr_node = index_of_first_random_node
        while sampled_graph.number_of_nodes() != upper_bound_nr_nodes_to_sample:
            edges = [n for n in complete_graph.neighbors(curr_node)]

            # Adding the condition test for avoid the index overflow!  Author: Junpeng Zhu Time: 2019/9/6 20:00
            while(len(edges) == 0):
                # print("current node has not edges!")
                index_of_first_random_node = random.randint(0, nr_nodes-1)   # reseed the current node
                curr_node = index_of_first_random_node   # reselect the current node as seed
                edges = [n for n in complete_graph.neighbors(curr_node)]

            index_of_edge = random.randint(0, len(edges) - 1)
            chosen_node = edges[index_of_edge]
            sampled_graph.add_node(chosen_node)
            sampled_graph.add_edge(curr_node, chosen_node)
            curr_node = chosen_node
            iteration = iteration+1

            if iteration % self.T == 0:
                if ((sampled_graph.number_of_edges() - edges_before_t_iter) < self.growth_size):
                    curr_node = random.randint(0, nr_nodes-1)
                edges_before_t_iter = sampled_graph.number_of_edges()
        return sampled_graph

    def random_walk_sampling_with_fly_back(self,complete_graph, nodes_to_sample, fly_back_prob):
        complete_graph = nx.convert_node_labels_to_integers(complete_graph, 0, 'default', True)
        # giving unique id to every node same as built-in function id
        for n, data in complete_graph.nodes(data=True):
            complete_graph.node[n]['id'] = n

        nr_nodes = len(complete_graph.nodes())
        upper_bound_nr_nodes_to_sample = nodes_to_sample

        index_of_first_random_node = random.randint(0, nr_nodes-1)
        sampled_graph = nx.Graph()

        sampled_graph.add_node(complete_graph.node[index_of_first_random_node]['id'])

        iteration = 1
        edges_before_t_iter = 0
        curr_node = index_of_first_random_node
        while sampled_graph.number_of_nodes() != upper_bound_nr_nodes_to_sample:
            edges = [n for n in complete_graph.neighbors(curr_node)]

            # Adding the condition test for avoid the index overflow!  Author: Junpeng Zhu Time: 2019/9/6 20:00
            while(len(edges) == 0):
                # print("current node has not edges!")
                index_of_first_random_node = random.randint(0, nr_nodes-1)   # reseed the current node
                curr_node = index_of_first_random_node   # reselect the current node as seed
                edges = [n for n in complete_graph.neighbors(curr_node)]

            index_of_edge = random.randint(0, len(edges) - 1)
            chosen_node = edges[index_of_edge]
            sampled_graph.add_node(chosen_node)
            sampled_graph.add_edge(curr_node, chosen_node)
            choice = np.random.choice(['prev','neigh'], 1, p=[fly_back_prob,1-fly_back_prob])
            if choice == 'neigh':
                curr_node = chosen_node
            iteration=iteration+1

            if iteration % self.T == 0:
                if ((sampled_graph.number_of_edges() - edges_before_t_iter) < self.growth_size):
                    curr_node = random.randint(0, nr_nodes-1)
                    print ("Choosing another random node to continue random walk ")
                edges_before_t_iter = sampled_graph.number_of_edges()

        return sampled_graph

    def random_walk_induced_graph_sampling(self, complete_graph, nodes_to_sample):
        complete_graph = nx.convert_node_labels_to_integers(complete_graph, 0, 'default', True)
        # giving unique id to every node same as built-in function id
        for n, data in complete_graph.nodes(data=True):
            complete_graph.node[n]['id'] = n
            
        nr_nodes = len(complete_graph.nodes())
        upper_bound_nr_nodes_to_sample = nodes_to_sample
        index_of_first_random_node = random.randint(0, nr_nodes - 1)

        Sampled_nodes = set([complete_graph.node[index_of_first_random_node]['id']])

        iteration = 1
        nodes_before_t_iter = 0
        curr_node = index_of_first_random_node
        while len(Sampled_nodes) != upper_bound_nr_nodes_to_sample:
            edges = [n for n in complete_graph.neighbors(curr_node)]

            # Adding the condition test for avoid the index overflow!  Author: Junpeng Zhu Time: 2019/9/6 20:00
            while(len(edges) == 0):
                # print("current node has not edges!")
                index_of_first_random_node = random.randint(0, nr_nodes-1)   # reseed the current node
                curr_node = index_of_first_random_node   # reselect the current node as seed
                edges = [n for n in complete_graph.neighbors(curr_node)]

            index_of_edge = random.randint(0, len(edges) - 1)
            chosen_node = edges[index_of_edge]
            Sampled_nodes.add(complete_graph.node[chosen_node]['id'])
            curr_node = chosen_node
            iteration=iteration+1

            if iteration % self.T == 0:
                if ((len(Sampled_nodes) - nodes_before_t_iter) < self.growth_size):
                    curr_node = random.randint(0, nr_nodes - 1)
                nodes_before_t_iter = len(Sampled_nodes)

        sampled_graph = complete_graph.subgraph(Sampled_nodes)

        return sampled_graph


if __name__ == "__main__":
    file = input("please input file path and name:")
    g = read_txt_to_undirected_graph(file)
    # make an object and call function SRW
    object1=SRW_RWF_ISRW()
    sample1 = object1.random_walk_sampling_simple(g,100) # graph, number of nodes to sample
    print("Simple Random Walk Sampling:")
    print("Number of nodes sampled=",len(sample1.nodes()))
    print("Number of edges sampled=",len(sample1.edges()))

    # make an object and call function RWF
    object2=SRW_RWF_ISRW()
    sample2= object2.random_walk_sampling_with_fly_back(g,110,0.2)  # graph, number of nodes to sample, fly-back probability
    print("Random Walk Sampling with flyback:")
    print("Number of nodes sampled=",len(sample2.nodes()))
    print("Number of edges sampled=",len(sample2.edges()))

    # make an object and call function ISRW
    object3=SRW_RWF_ISRW()
    sample3= object3.random_walk_induced_graph_sampling(g,1000)  # graph, number of nodes to sample
    print("Induced Subgraph Random Walk Sampling:")
    print ("Number of nodes sampled=",len(sample3.nodes()))
    print ("Number of edges sampled=",len(sample3.edges()))
