import networkx as nx
import sys

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
    readUndirectedGraph("GML.txt")
