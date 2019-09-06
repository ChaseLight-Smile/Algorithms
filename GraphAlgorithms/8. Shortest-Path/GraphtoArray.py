import networkx as nx
import sys
import numpy as np


def readDirectedGraph(file):
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
    G = readDirectedGraph("test.txt")
    print("---",G.nodes())
    matrix = nx.to_numpy_matrix(G)
    print(matrix)
    # matrix = nx.adjacency_matrix(G)
    lmatrix = matrix.tolist()

    lmatrix_size = len(lmatrix)
    for i in range(lmatrix_size):
        lmatrix_elements = lmatrix[i]
        # print(type(lmatrix_elements))
        lmatrix_elements_size = len(lmatrix_elements)
        for j in range(lmatrix_elements_size):
            if lmatrix_elements[j] == 0.0:
                lmatrix_elements[j] = float("inf")
                print(lmatrix_elements[j],end=",")
            else:
                print(int(lmatrix_elements[j]), end=",")
        print(end="\n")

