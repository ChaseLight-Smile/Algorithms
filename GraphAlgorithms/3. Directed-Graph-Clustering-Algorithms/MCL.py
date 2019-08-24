import networkx as nx
import numpy as np
from optparse import OptionParser
import logging
import xlrd
import sys
import collections
import matplotlib.pyplot as plt
import warnings
import matplotlib.cbook
warnings.filterwarnings("ignore",category=matplotlib.cbook.mplDeprecation)
import os
from networkx.algorithms.bridges import bridges
from networkx.algorithms.isolate import isolates

def read(file, sheet_index=0):
    G = nx.DiGraph()
    workbook1 = xlrd.open_workbook(file)
    sheet1 = workbook1.sheet_by_index(sheet_index)
    try:
        for i in range(1, sheet1.nrows):
            G.add_edge(sheet1.row_values(i)[0],sheet1.row_values(i)[8], weight = 1)
        nx.write_gml(G,'Project111111111111.txt')
    except:
        print("Unexpected error:", sys.exc_info())
        input('press enter key to exit')

def normalize(A):
    column_sums = A.sum(axis=0)
    new_matrix = A / column_sums[np.newaxis, :]
    return new_matrix

def inflate(A, inflate_factor):
    return normalize(np.power(A, inflate_factor))

def expand(A, expand_factor):
    return np.linalg.matrix_power(A, expand_factor)

def add_diag(A, mult_factor):
    return A + mult_factor * np.identity(A.shape[0])

def get_clusters(A):
    clusters = []
    for i, r in enumerate((A>0).tolist()):
        if r[i]:
            clusters.append(A[i,:]>0)

    clust_map  ={}
    for cn , c in enumerate(clusters):
        for x in  [ i for i, x in enumerate(c) if x ]:
            clust_map[cn] = clust_map.get(cn, [])  + [x]
    return clust_map

def draw(G, A, cluster_map):   #画出来最终的聚类结果
    import networkx as nx
    import matplotlib.pyplot as plt

    clust_map = {}
    for k, vals in cluster_map.items():
        for v in vals:
            clust_map[v] = k

    colors = []
    for i in range(len(G.nodes())):
        colors.append(clust_map.get(i, 100))

    pos = nx.spring_layout(G)

    from matplotlib.pylab import matshow, show, cm
    plt.figure(200)
    nx.draw_networkx_nodes(G, pos,node_size = 500, node_color =colors , cmap=plt.cm.Blues )
    nx.draw_networkx_edges(G,pos, alpha=0.5)
    nx.draw_networkx_labels(G,pos)
    matshow(A, fignum=1, cmap=cm.gray)
    plt.show()
    show()


def stop(M, i):

    if i%5==4:
        m = np.max( M**2 - M) - np.min( M**2 - M)
        if m==0:
            logging.info("Stop at iteration %s" % i)
            return True

    return False


def mcl(M, expand_factor = 2, inflate_factor = 2, max_loop = 10 , mult_factor = 1):
    M = add_diag(M, mult_factor)
    M = normalize(M)

    for i in range(max_loop):
        logging.info("loop %s" % i)
        M = inflate(M, inflate_factor)
        M = expand(M, expand_factor)
        if stop(M, i): break

    clusters = get_clusters(M)
    return M, clusters

def networkx_mcl(G, expand_factor = 2, inflate_factor = 2, max_loop = 10 , mult_factor = 1):
    import networkx as nx
    A = nx.adjacency_matrix(G)
    return mcl(np.array(A.todense()), expand_factor, inflate_factor, max_loop, mult_factor)

def print_info(options):
    print("-" * 60)
    print("MARKOV CLUSTERING:")
    print("-" * 60)
    print("  expand_factor: %s" % options.expand_factor)
    print("  inflate_factor: %s" % options.inflate_factor)
    print("  mult factor: %s" % options.mult_factor)
    print("  max loops: %s\n" % options.max_loop)

def get_options():
    usage = "usage: %prog [options] <input_matrix>"
    parser = OptionParser(usage)
    parser.add_option("-e", "--expand_factor",
                      dest="expand_factor",
                      default=2,
                      type=int,
                      help="expand factor (default: %default)")
    parser.add_option("-i", "--inflate_factor",
                      dest="inflate_factor",
                      default=2,
                      type=float,
                      help="inflate factor (default: %default)")
    parser.add_option("-m", "--mult_factor",
                      dest="mult_factor",
                      default=2,
                      type=float,
                      help="multiply factor (default: %default)")
    parser.add_option("-l", "--max_loops",
                      dest="max_loop",
                      default=60,
                      type=int,
                      help="max loops (default: %default)")
    parser.add_option("-o", "--output", metavar="FILE",
                      help="output (default: stdout)")

    parser.add_option("-v", "--verbose",
                      action="store_true", dest="verbose", default=True,
                      help="verbose (default: %default)")
    parser.add_option("-d", "--draw-graph",
                      action="store_true", dest="draw", default=False,
                      help="show graph with networkx (default: %default)")


    (options, args) = parser.parse_args()

    try:
        filename = args[0]
    except:
        raise Exception('input', 'missing input filename')


    return options, filename

def get_graph(csv_filename):
    import networkx as nx

    M = []
    for r in open(csv_filename):
        r = r.strip().split(",")
        M.append(list(map(lambda x: float(x.strip()), r)))

    G = nx.from_numpy_matrix(np.matrix(M))
    return np.array(M), G

def clusters_to_output(clusters, options):
    if options.output and len(options.output)>0:
        f = open(options.output, 'w')
        for k, v in clusters.items():
            f.write("%s|%s\n" % (k, ", ".join(map(str, v)) ))
        f.close()
    else:
        print("Clusters:")
        for k, v in clusters.items():
            print('{}, {}'.format(k, v))


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

    # print("--------判断任意两点的共同祖先--------")
    # ancestors = nx.all_pairs_lowest_common_ancestor(G)
    # print("任意两对的祖先为:", ancestors)
    # print("--------判断任意两点的共同祖先--------")
    # print("----------发现环-----------")

    CycleGraph = nx.DiGraph()
    cedges = list(nx.find_cycle(G, orientation='ignore'))
    print(cedges)
    cycleEdges = []
    t = tuple()
    for e in cedges:
        print(type(e[2]))
        if e[2] == "forward":
            t = e[0], e[1]
            cycleEdges.append(t)
        else:
            t = e[1], e[0]
            cycleEdges.append(t)
    CycleGraph.add_edges_from(cycleEdges)
    nx.draw(CycleGraph, with_labels = True)
    plt.show()
    print("----------发现环-----------")
    print("度为0的点为:", list(isolates(G)))

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
    plt.axes([0.4, 0.4, 0.5, 0.5])
    Gcc = sorted(nx.strongly_connected_component_subgraphs(G), key=len, reverse=True)[0]
    pos = nx.spring_layout(G)
    plt.axis('off')
    nx.draw_networkx_nodes(G, pos, node_size=20)
    nx.draw_networkx_edges(G, pos, alpha=0.4)
    print("---", len(Gcc))
    plt.show()

    input("输入")
    ###########################
    in_degree_sequence = sorted([d for n, d in G.in_degree()], reverse=True)
    print(in_degree_sequence)
    in_degreeCount = collections.Counter(in_degree_sequence)
    deg, cnt = zip(*in_degreeCount.items())

    fig, ax = plt.subplots()
    plt.bar(deg, cnt, width=0.80, color='b')

    plt.title("in_Degree Histogram")
    plt.ylabel("Count")
    plt.xlabel("in_Degree")
    ax.set_xticks([d + 0.4 for d in deg])
    ax.set_xticklabels(deg)
    ###########################
    plt.axes([0.4, 0.4, 0.5, 0.5])
    Gcc = sorted(nx.strongly_connected_component_subgraphs(G), key=len, reverse=True)[0]
    pos = nx.spring_layout(G)
    plt.axis('off')
    nx.draw_networkx_nodes(G, pos, node_size=20)
    nx.draw_networkx_edges(G, pos, alpha=0.4)
    print("---", len(Gcc))
    plt.show()
    input("输入")

    ###########################
    out_degree_sequence = sorted([d for n, d in G.out_degree()], reverse=True)
    print(out_degree_sequence)
    out_degreeCount = collections.Counter(out_degree_sequence)
    deg, cnt = zip(*out_degreeCount.items())

    fig, ax = plt.subplots()
    plt.bar(deg, cnt, width=0.80, color='b')

    plt.title("out_Degree Histogram")
    plt.ylabel("Count")
    plt.xlabel("out_Degree")
    ax.set_xticks([d + 0.4 for d in deg])
    ax.set_xticklabels(deg)
    ############################
    plt.axes([0.4, 0.4, 0.5, 0.5])
    Gcc = sorted(nx.strongly_connected_component_subgraphs(G), key=len, reverse=True)[0]
    pos = nx.spring_layout(G)
    plt.axis('off')
    nx.draw_networkx_nodes(G, pos, node_size=20)
    nx.draw_networkx_edges(G, pos, alpha=0.4)
    print("---", len(Gcc))
    plt.show()
    input("输入")

    # draw graph in inset
    # plt.axes([0.4, 0.4, 0.5, 0.5])
    # Gcc = sorted(nx.strongly_connected_component_subgraphs(G), key=len, reverse=True)[0]
    # pos = nx.spring_layout(G)
    # plt.axis('off')
    # nx.draw_networkx_nodes(G, pos, node_size=20)
    # nx.draw_networkx_edges(G, pos, alpha=0.4)
    # print("---", len(Gcc))
    # plt.show()

    # print(networkx_mcl(G)[0])
    print("有向图聚类后的簇数目为：", len(networkx_mcl(G)[1]))
    print("有向图聚类结果为：", networkx_mcl(G)[1])
    draw(G,networkx_mcl(G)[0],networkx_mcl(G)[1])
