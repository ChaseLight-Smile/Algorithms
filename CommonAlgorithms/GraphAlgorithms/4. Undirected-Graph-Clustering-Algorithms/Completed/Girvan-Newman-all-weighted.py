# -*- coding: utf-8 -*-
import networkx as nx
import matplotlib.pyplot as plt
import xlrd
import sys

def read(file, sheet_index=0):
    G = nx.Graph()
    workbook1 = xlrd.open_workbook(file)
    sheet1 = workbook1.sheet_by_index(sheet_index)
    try:
        for i in range(1, sheet1.nrows):
            G.add_edge(sheet1.row_values(i)[0],sheet1.row_values(i)[8], weight = 1)   #将每一行的第0列和第8列加入到图的边中
        nx.write_gml(G,'Project111111111111.txt')
    except:
        print("Unexpected error:", sys.exc_info())# sys.exc_info()返回出错信息
        input('press enter key to exit') #这儿放一个等待输入是为了不让程序退出

class GN_w:
    def __init__(self, G):
        self.G_copy = G.copy()
        self.G = G
        self.partition = [[n for n in G.nodes()]]
        self.all_Q = [0.0]
        self.max_Q = 0.0

    def run(self):
#		#Until there is no edge in the graph
#        while len(self.G.edges()) != 0:
#			#Find the most betweenness edge
#            edge = max(nx.edge_betweenness_centrality(self.G).items(),key=lambda item:item[1])[0]
#            #Remove the most betweenness edge
#            self.G.remove_edge(edge[0], edge[1])
#			#List the the connected nodes
#            components = [list(c) for c in list(nx.connected_components(self.G))]
#            if len(components) != len(self.partition):
#				#compute the Q
#                cur_Q = self.cal_Q(components, self.G_copy)
#                if cur_Q not in self.all_Q:
#                    self.all_Q.append(cur_Q)
#                if cur_Q > self.max_Q:
#                    self.max_Q = cur_Q
#                    self.partition = components
#            
#        print('-----------the Max Q and divided communities-----------')
#        print('The number of Communites:', len(self.partition))
#        print("Communites:", self.partition)
#        print('Max_Q:', self.max_Q)
#        return self.partition, self.all_Q, self.max_Q
       
        while len(self.G.edges()) != 0:
            edges={}
            edges_betweenness_centrality = nx.edge_betweenness_centrality(self.G)
            
            for e, ebc in edges_betweenness_centrality.items():
                edge_weight = ebc/self.G.get_edge_data(e[0],e[1])['weight']
                edges[e]=edge_weight
                
            edge = max(edges.items(), key=lambda item:item[1])[0]
            self.G.remove_edge(edge[0], edge[1])
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
        #plt.axhline(self.all_Q[3],color='red',linestyle="--")
        plt.show()
    
    def add_group(self):
        num = 0
        nodegroup = {}
        for partition in self.partition:
            for node in partition:
                nodegroup[node] = {'group':num}
            num = num + 1  
        nx.set_node_attributes(self.G_copy, nodegroup)
        
    def to_gml(self):
        nx.write_gml(self.G_copy, 'outputofGN_weighted.gml')
    
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
        
if __name__ == '__main__':
    read("数据清洗4520116720190610183042流水合并.xlsx")
    G=nx.read_gml('Project111111111111.txt',label='id')
    print("构建图完成")

    algorithm = GN_w(G)
    algorithm.run()
    algorithm.add_group()
    algorithm.draw_Q()
    algorithm.to_gml()
    input()
   
