#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 11 21:20:56 2018

@author: yubiabia
"""

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 11 17:20:07 2018

@author: yubiabia
"""
import collections,random
import networkx as nx
import matplotlib.pyplot as plt


def communities(Label, Neighbor):
    communities={}
    i=0
    for l in set(Label.values()):
        i=i+1
        community=[node for node in Label if Label[node]==l]
        communities.update({i:community})
    return communities
    

def maxVote(nLabels):
    cnt = collections.defaultdict(int)
    for i in nLabels:
        cnt[i] += 1
    maxv = max(cnt.values())
    return random.choice([k for k,v in cnt.items() if v == maxv])

def Stop(Label,Neighbor):
    for n in Label: #for each node
        if Label[n]!= max(Neighbor[n],key=Neighbor[n].count): #the label of the node should be the max
            return False
    return True #all rach max cnt of labels

def createEdges(NeighborID):
    edges=[]
    for node in NeighborID:
        for i in NeighborID[node]:
            edges.append((node,i))
    return edges
        

Label={}  #store nodes' labels
Neighbor={} #store neighbors' labels
NeighborID={} #store neighbors ID
f= open("three.txt","w+")
f.write("4,2,5"+'\n')
f.write("5,4,2,1"+'\n')
f.write("2,4,3,5,1"+'\n')
f.write("1,3,4,2,5"+'\n')
f.write("3,5,2,1"+'\n')
f.write("6,7,8,9"+'\n')
f.write("7,8,9"+'\n')
f.write("10,8"+'\n')
f.write("9,8,10"+'\n')
f.write("8,9,10,4"+'\n')
f.write("11,12,13,14,2"+'\n')
f.write("14,12,13,11,3"+'\n')
f.write("12,11,13,14,8"+'\n')
f.write("13,12,11,14,8,3"+'\n')
f.close()
#create testing sample
data=open('three.txt',"r")
for line in data:
    entry=line.rstrip('\n').split(',')
    node=entry[0]
    neighborID=[k for k in entry[1:]]#store neighbor ID in list
    Label.update({node:int(node)})#assign unique label for each node
    NeighborID.update({node:neighborID}) #add neighborID to NeighborID dictionary

edges=createEdges(NeighborID) #transform neighbors to edges
G=nx.Graph()
G.add_edges_from(edges)
pos=nx.spring_layout(G)
colors = ["orange","red","blue","green","yellow","indigo","pink"]
C=communities(Label,Neighbor)
print(C)



for i in C:
    graph=C[i]
    nlist = [node for node in graph]
    nx.draw_networkx_nodes(G,pos,nodelist=nlist,node_color=colors[i%7],node_size=250,alpha=1.0)
nx.draw_networkx_edges(G, pos)
nx.draw_networkx_labels(G,pos,font_size=15,font_color="white")
plt.axis('off')
for n in NeighborID: #for each node
    Lneighbor=[Label[k] for k in NeighborID[n]] #collect its neighbors labels 
    Neighbor.update({n:Lneighbor})# add to Neighbor dictionary
#acquire each node's neighbors' labels
iteration=1
while Stop(Label,Neighbor) is False:
#    print("# Run of Iteration : "+str(iteration))
    order=random.sample(list(Neighbor),len(Neighbor))
    for n in order:#random order
        Lneighbor=[Label[k] for k in NeighborID[n]] #update previously updated nodes
        Neighbor.update({n:Lneighbor})
        Label[n]=maxVote(Neighbor[n]) #update its own label
        C=communities(Label,Neighbor)
#vote and apply max ID
    
    print(iteration)
    print(Label)
    iteration=iteration+1
#iterations
print ("Iterations in total : "+str(iteration))
C=communities(Label,Neighbor)

for i in C:
    graph=C[i]
    nlist = [node for node in graph]
    nx.draw_networkx_nodes(G,pos,nodelist=nlist,node_color=colors[i%7],node_size=250,alpha=1.0)
nx.draw_networkx_edges(G, pos)
#nx.draw_networkx_labels(G,pos,font_size=15,font_color="white")
plt.axis('off')