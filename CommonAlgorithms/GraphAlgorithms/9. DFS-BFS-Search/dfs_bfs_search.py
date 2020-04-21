import uuid
import networkx as nx
import matplotlib.pyplot as plt
import os
import xlrd

def read(file, sheet_index=0):
    G = nx.Graph()
    workbook1 = xlrd.open_workbook(file)
    sheet1 = workbook1.sheet_by_index(sheet_index)
    try:
        for i in range(1, sheet1.nrows):
            G.add_edge(sheet1.row_values(i)[0],sheet1.row_values(i)[8], weight = 1)
        nx.write_gml(G,'Project111111111111.txt')
    except:
        print("Unexpected error:", sys.exc_info())
        input('press enter key to exit')

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

    while(1):
        start = input("输入起始点：")
        bfs_Tree = nx.bfs_tree(G,int(start))
        print(len(bfs_Tree))
        print("起始点的广度遍历树为:", bfs_Tree.edges())
        G = nx.Graph()
        G.add_edges_from(bfs_Tree.edges())
        nx.draw(G, with_labels = True)
        plt.show()
        input()
        dfs_Tree = nx.dfs_tree(G,int(start))
        print(len(dfs_Tree))
        print("起始点的深度遍历树为:", dfs_Tree.edges())
        G = nx.Graph()
        G.add_edges_from(dfs_Tree.edges())
        nx.draw(G, with_labels = True)
        plt.show()

