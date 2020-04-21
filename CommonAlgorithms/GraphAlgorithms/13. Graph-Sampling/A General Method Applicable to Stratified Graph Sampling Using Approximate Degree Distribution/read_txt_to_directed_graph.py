import networkx as nx


def read_txt_to_directed_graph(filename):
    file = open(filename, 'r')
    G = nx.DiGraph()
    for line in file.readlines():
        node = line.split()
        G.add_edge(node[0],node[1])
    tmp = filename.split('.')
    output_file = tmp[0] + "undiredted." + tmp[1]
    nx.write_gml(G, output_file)
    return G


if __name__ == "__main__":
    file = input("please input file path and name:")
    G = read_txt_to_directed_graph(file)
    print(nx.number_of_nodes(G))   #点的个数

    print(nx.number_of_edges(G))   #边的个数

    print(nx.average_clustering(G)) #平均聚类系数

    # print(nx.diameter(G)) #直径


    #计算平均度
    degrees = nx.degree(G)
    sum = 0
    for degree in degrees:
        sum = sum + int(degree[1])
    print(sum/nx.number_of_nodes(G))


    # 统计度分布情况
    degree_sequence = sorted([d for n, d in G.degree()], reverse=True)
    print(degree_sequence)
