import networkx as nx
import matplotlib.pyplot as plt
import sys
import warnings
warnings.filterwarnings('ignore')

def readMultiGraph(file):
    G = nx.MultiGraph()
    f = open(file)
    try:
        for line in f.readlines():
            cell = line.split()
            G.add_edge(cell[0],cell[1])
        nx.write_gml(G,'Project111111111111.txt')
    except:
        print("Unexpected error:", sys.exc_info())
        input('press enter key to exit')
    pos = nx.spring_layout(G)  # positions for all nodes
    print(pos)
    # nodes
    nx.draw_networkx_nodes(G, pos,
                       nodelist=['1', '2', '3', '8'],
                       node_color='r',
                       node_size=500,)
    nx.draw_networkx_nodes(G, pos,
                       nodelist=['a', 'b', 'c', 'd', 'e'],
                       node_color='g',
                       node_size=500,)

    nx.draw_networkx_edges(G, pos, width=1.0, alpha=0.5)
    nx.draw_networkx_labels(G, pos)
    plt.axis('off')   #在画图时去掉本身包含的平面坐标系
    plt.show()
    return G

if __name__ == '__main__':
    readMultiGraph("GML.txt")

