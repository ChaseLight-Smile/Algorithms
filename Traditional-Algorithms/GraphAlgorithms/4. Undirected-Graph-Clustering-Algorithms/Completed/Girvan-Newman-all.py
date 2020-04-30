# -*- coding: utf-8 -*-
import networkx as nx
import matplotlib.pyplot as plt
import xlrd
import sys
import collections
import os

def read(file, sheet_index=0):
    G = nx.Graph()
    workbook1 = xlrd.open_workbook(file)
    sheet1 = workbook1.sheet_by_index(sheet_index)
    try:
        for i in range(1, sheet1.nrows):
            G.add_edge(sheet1.row_values(i)[0],sheet1.row_values(i)[8])   #将每一行的第0列和第8列加入到图的边中
        nx.write_gml(G,'Project111111111111.txt')
    except:
        print("Unexpected error:", sys.exc_info())# sys.exc_info()返回出错信息
        input('press enter key to exit') #这儿放一个等待输入是为了不让程序退出

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
        #print(G.nodes())
        for partition in self.partition:
            for node in partition:
                nodegroup[node] = {'group':num}
            num = num + 1
        nx.set_node_attributes(self.G_copy, nodegroup)
        print(self.G_copy.nodes())
        
    def to_gml(self):
        nx.write_gml(self.G_copy, 'outputofGN.gml')
        
if __name__ == '__main__':
    path_input = input("请输入需要清洗的数据文件路径：")
    # input_flag = os.path.exists(path_input)
    while (True):
        input_flag = os.path.exists(path_input)
        if (input_flag):
            break
        else:
            path_input = input("请重新输入需要清洗的数据文件路径：")
    read(path_input)
    print("构建图完成")
    G=nx.read_gml('Project111111111111.txt',label='id')

    # 显示该图的度分布
    degree_sequence = sorted([d for n, d in G.degree()], reverse=True)
    print(degree_sequence)
    degreeCount = collections.Counter(degree_sequence)
    deg, cnt = zip(*degreeCount.items())

    fig, ax = plt.subplots()
    plt.bar(deg, cnt, width=0.80, color='b')

    plt.title("Degree Histogram")
    plt.ylabel("Count")
    plt.xlabel("Degree")
    ax.set_xticks([d + 0.4 for d in deg])
    ax.set_xticklabels(deg)

    # draw graph in inset
    plt.axes([0.4, 0.4, 0.5, 0.5])
    Gcc = sorted(nx.connected_component_subgraphs(G), key=len, reverse=True)[0]
    pos = nx.spring_layout(G)
    plt.axis('off')
    nx.draw_networkx_nodes(G, pos, node_size=20)
    nx.draw_networkx_edges(G, pos, alpha=0.4)
    plt.show()


    algorithm = GN(G)
    algorithm.run()
    algorithm.draw_Q()   #画出Q值的曲线图
    algorithm.add_group()
    algorithm.to_gml()


    G1=nx.read_gml('Project111111111111.txt',label='id') #Dividing communities by the number
    algorithmByNum = GN(G1)
    algorithmByNum.run_n(2)
    
    G2=nx.read_gml('Project111111111111.txt',label='id') #Dividing communities until each node is a community
    algorithmtoOne = GN(G2)
    some = algorithmtoOne.run_to_all()
    print('-----------the result of each division, until each node is a community----------')
    for i in range(1,len(G.nodes())+1):
        print('\n划分成{0}个社区：Q值为{1}'.format(i, some[1][i-1]))
        print(some[0][i-1])
   
