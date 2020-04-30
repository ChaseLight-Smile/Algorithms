import networkx as nx
import sys
import collections
import matplotlib.pyplot as plt

def readUndirectedGraph(file):
    G = nx.Graph()
    f = open(file)
    try:
        for line in f.readlines():
            cell = line.split()
            G.add_edge(cell[0],cell[1])
        nx.write_gml(G,'Project111111111111.txt')
    except:
        print("Unexpected error:", sys.exc_info())
        input('press enter key to exit')
    return G

if __name__ == '__main__':
    G = readUndirectedGraph("GML.txt")
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
