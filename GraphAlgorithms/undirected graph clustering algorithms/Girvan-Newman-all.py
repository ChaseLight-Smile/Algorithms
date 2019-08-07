# -*- coding: utf-8 -*-

import networkx as nx
import matplotlib.pyplot as plt
import sys
sys.path.append('../')

class GN:
    def __init__(self, G):
        self.G_copy = G.copy()
        self.G = G
        self.partition = [[n for n in G.nodes()]]
        self.all_Q = [0.0]
        self.max_Q = 0.0
		
    #Using max_Q to divide communities 
    def run(self):
		#Until there is no edge in the graph
        while len(self.G.edges()) != 0:
			#Find the most betweenness edge
            edge = max(nx.edge_betweenness_centrality(self.G).items(),key=lambda item:item[1])[0]
			#Remove the most betweenness edge
            self.G.remove_edge(edge[0], edge[1])
			#List the the connected nodes
            components = [list(c) for c in list(nx.connected_components(self.G))]
            if len(components) != len(self.partition):
				#compute the Q
                cur_Q = self.cal_Q(components, self.G_copy)
                if cur_Q not in self.all_Q:
                    self.all_Q.append(cur_Q)
                if cur_Q > self.max_Q:
                    self.max_Q = cur_Q
                    self.partition = components
            
        print('-----------the Max Q and divided communities-----------')
        print('The number of Communites:', len(self.partition))
        print("Communites:", self.partition)
        print('Max_Q:', self.max_Q)
        return self.partition, self.all_Q, self.max_Q
    
	#Dividing communities by number
    def run_n(self, k):
        while len(self.G.edges()) != 0:
            edge = max(nx.edge_betweenness_centrality(self.G).items(),key=lambda item:item[1])[0]
            self.G.remove_edge(edge[0], edge[1])
            components = [list(c) for c in list(nx.connected_components(self.G))]
            if len(components) <= k:
                cur_Q = self.cal_Q(components, self.G_copy)
                if cur_Q not in self.all_Q:
                    self.all_Q.append(cur_Q)
                if cur_Q > self.max_Q:
                    self.max_Q = cur_Q
                    self.partition = components
        print('-----------Using number to divide communities and the Q-----------')
        print('The number of Communites', len(self.partition))
        print("Communites: ", self.partition)
        print('Max_Q: ', self.max_Q)
        return self.partition, self.all_Q, self.max_Q
    
    #the process of divding the network
    #Return a list containing the result of each division, until each node is a community
    def run_to_all(self):
        divide = []
        all_Q = []
        while len(self.G.edges()) != 0:
            edge = max(nx.edge_betweenness_centrality(self.G).items(),key=lambda item:item[1])[0]
            self.G.remove_edge(edge[0], edge[1])
            components = [list(c) for c in list(nx.connected_components(self.G))]
            if components not in divide:
                divide.append(components)
            cur_Q = self.cal_Q(components, self.G_copy)
            if cur_Q not in all_Q:
                all_Q.append(cur_Q)
        return divide, all_Q
       
	#Drawing the graph of Q and divided communities
    def draw_Q(self):
        plt.plot([x for x in range(1,len(self.G.nodes)+1)],self.all_Q)
        my_x_ticks = [x for x in range(1,len(self.G.nodes)+1)]
        plt.xticks(my_x_ticks)
        plt.axvline(len(self.partition),color='black',linestyle="--")
        plt.axvline(2, color='black',linestyle="--")
        #plt.axhline(self.all_Q[3],color='red',linestyle="--")
        plt.show()
    
	#Computing the Q
    def cal_Q(self,partition,G):
        m = len(G.edges(None, False))
        a = []
        e = []
    
        for community in partition:
            t = 0.0
            for node in community:
                t += len([x for x in G.neighbors(node)])
            a.append(t/(2*m))
        
        for community in partition:
            t = 0.0
            for i in range(len(community)):
                for j in range(len(community)):
                    if(G.has_edge(community[i], community[j])):
                        t += 1.0
            e.append(t/(2*m))
        
        q = 0.0
        for ei,ai in zip(e,a):
            q += (ei - ai**2) 
        return q 
    
    def add_group(self):
        num = 0
        nodegroup = {}
        for partition in self.partition:
            for node in partition:
                nodegroup[node] = {'group':num}
            num = num + 1  
        nx.set_node_attributes(self.G_copy, nodegroup)
        
    def to_gml(self):
        nx.write_gml(self.G_copy, 'outputofGN.gml')
        
if __name__ == '__main__':
    G=nx.read_gml('..\datasets\karate.gml',label='id') #Using max_Q to divide communities 
    algorithm = GN(G)
    algorithm.run()
    algorithm.draw_Q()
    algorithm.add_group()
    algorithm.to_gml()
	
    G1=nx.read_gml('..\datasets\karate.gml',label='id') #Dividing communities by the number
    algorithmByNum = GN(G1)
    algorithmByNum.run_n(2)
    
    G2=nx.read_gml('karate.gml',label='id') #Dividing communities until each node is a community
    algorithmtoOne = GN(G2)
    some = algorithmtoOne.run_to_all()
    print('-----------the result of each division, until each node is a community----------')
    for i in range(1,len(G.nodes())+1):
        print('\n划分成{0}个社区：Q值为{1}'.format(i, some[1][i-1]))
        print(some[0][i-1])
   
    