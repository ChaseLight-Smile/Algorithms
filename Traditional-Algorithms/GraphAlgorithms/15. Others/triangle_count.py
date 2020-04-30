# 无向图统计三角形的个数
import networkx as nx
import itertools

def read_txt_to_undirected_graph(filename):
    file = open(filename, 'r')
    G = nx.Graph()
    for line in file.readlines():
        node = line.split()
        G.add_edge(node[0],node[1])
    # tmp = filename.split('.')
    # output_file = tmp[0] + "undiredted." + tmp[1]
    # nx.write_gml(G, output_file)
    return G


def wedge_iterator(graph):
    for node in graph.nodes():
        neighbors = graph.neighbors(node)
        for pair in itertools.combinations(neighbors, 2):
            yield (node, pair)


def count_triangle(graph):
    n = 0
    for wedge in wedge_iterator(graph):
        if graph.has_edge(wedge[1][0], wedge[1][1]) or graph.has_edge(wedge[1][1], wedge[1][0]):
            n += 1
    return n

if __name__ == "__main__":
    file = input("please input file path and name:")
    G = read_txt_to_undirected_graph(file)
    n = count_triangle(G)
    print(int(n/3))
