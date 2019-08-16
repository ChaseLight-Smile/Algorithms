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

#create testing sample
data=open('com-youtube.top5000.cmty.txt',"r")
for line in data:
    entry=line.rstrip('\n').split('\t')
    node=entry[0]
    neighborID=[k for k in entry[1:]]#store neighbor ID in list
    Label.update({node:int(node)})#assign unique label for each node
    NeighborID.update({node:neighborID}) #add neighborID to NeighborID dictionary

edges=createEdges(NeighborID) #transform neighbors to edges
G=nx.Graph()
G.add_edges_from(edges)
pos=nx.spring_layout(G)
colors=['red','blue','green','cyan','pink','orange','grey','yellow','white','black','purple' ]



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

    """print(iteration)
    print(Label)"""
    iteration=iteration+1
#iterations
print ("Iterations in total : "+str(iteration))
C=communities(Label,Neighbor)

for i in C:
    graph=C[i]
    nlist = [node for node in graph]
    nx.draw_networkx_nodes(G,pos,nodelist=nlist,node_color=colors[i%11],node_size=15,alpha=1.0)
nx.draw_networkx_edges(G, pos)
#nx.draw_networkx_labels(G,pos,font_size=15,font_color="white")
plt.axis('off')
