# -*- coding: UTF-8 -*-
import random
import networkx as nx
import matplotlib.pyplot as plt
import xlrd

def read_graph_from_file_txt(path):
    graph = nx.Graph()
    # 获取边列表edges_list
    edges_list = []
    # 开始获取边
    fp = open(path)
    edge = fp.readline().split()
    while edge:
        if edge[0].isdigit() and edge[1].isdigit():
            edges_list.append((int(edge[0]), int(edge[1])))
        edge = fp.readline().split()
    fp.close()
    # 为图增加边
    graph.add_edges_from(edges_list)

    # 给每个节点增加标签
    for node, data in graph.nodes(True):
        data['label'] = node

    return graph


def read_graph_from_file(file,sheet_index = 0):
    graph = nx.Graph()
    workbook1 = xlrd.open_workbook(file)
    sheet1 = workbook1.sheet_by_index(sheet_index)
    for i in range(1, sheet1.nrows):
        graph.add_edge(sheet1.row_values(i)[0],sheet1.row_values(i)[8])   #将每一行的第0列和第8列加入到图的边中
    # 给每个节点增加标签
    for node, data in graph.nodes(True):
        data['label'] = node
    return graph


def lpa(graph):
    def estimate_stop_condition():
        """
        算法终止条件：所有节点的标签与大部分邻居节点标签相同或者迭代次数超过指定值则停止
        :return:
        """
        for node in graph.nodes():
            count = {}
            for neighbor in graph.neighbors(node):
                neighbor_label = graph.node[neighbor]['label']
                count[neighbor_label] = count.setdefault(
                    neighbor_label, 0) + 1

            # 找到计数值最大的label
            count_items = count.items()
            sorted(count_items, key=lambda x: x[1], reverse=True)
            labels = [k for k, v in count_items if v == list(count_items)[0][1]]
            # 当节点标签与大部分邻居节点标签相同时则达到停止条件
            if graph.node[node]['label'] not in labels:
                return False

        return True

    loop_count = 0

    # 迭代标签传播过程
    while True:
        loop_count += 1
        print('迭代次数', loop_count)

        for node in graph.nodes():
            count = {}
            for neighbor in graph.neighbors(node):
                neighbor_label = graph.node[neighbor]['label']
                count[neighbor_label] = count.setdefault(
                    neighbor_label, 0) + 1

            # 找到计数值最大的标签
            count_items = count.items()
            # print count_items
            sorted(count_items, key=lambda x: x[1], reverse=True)
            labels = [(k, v) for k, v in count_items if v == list(count_items)[0][1]]
            # 当多个标签最大计数值相同时随机选取一个标签
            label = random.sample(labels, 1)[0][0]
            graph.node[node]['label'] = label

        if estimate_stop_condition() is True or loop_count >= 100:
            print('complete')
            return



if __name__ == "__main__":

    path = "数据清洗4520116720190610183042流水合并.xlsx"
    #path = "soc-Epinions1.txt"
    graph = read_graph_from_file(path)
    lpa(graph)

    # 根据算法结果画图
    node_color = [float(graph.node[v]['label']) for v in graph]
    nx.draw_networkx(graph, node_color=node_color)
    plt.show()
