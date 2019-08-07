import networkx as nx
class CommunitySearch:
    def __init__(self, G):
        self.G_copy = G.copy()
        self.G = G
        self.partition = [[n for n in G.nodes()]]
        self.all_Q = [0.0]
 
    def devide_community(self):
        divide = []
        all_Q = []
        #计算betweenness,这个过程会反复计算最短路径，整个是算法最慢的部分，当然理论上算法的时间复杂度为多项式时间
        while len(self.G.edges()) != 0:
            #寻找betweenness值最大的边
            edge = max(nx.edge_betweenness_centrality(self.G).items(),key=lambda item:item[1])[0]
            #删除上述边
            self.G.remove_edge(edge[0], edge[1])
            components = [list(c) for c in list(nx.connected_components(self.G))]
            if components not in divide:
                divide.append(components)
            q = self.computing_q(components, self.G_copy)
            if q not in all_Q:
                all_Q.append(q)
        return divide, all_Q

    def computing_q(self,partition,G):
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
    
    def devide_group(self):
        num = 0
        nodegroup = {}
        for partition in self.partition:
            for node in partition:
                nodegroup[node] = {'group':num}
            num = num + 1  
        nx.set_node_attributes(self.G_copy, nodegroup)

if __name__ == '__main__':
    G=nx.read_gml('karate.gml',label='id')
    c = CommunitySearch(G)
    cc = c.devide_community()
    for i in range(1,len(G.nodes())+1):
        print(cc[0][i-1])
