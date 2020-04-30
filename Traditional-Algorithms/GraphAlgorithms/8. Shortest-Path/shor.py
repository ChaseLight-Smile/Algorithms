import networkx as nx
import xlrd
import sys
import os
def read(file, sheet_index=0):
    G = nx.Graph()
    workbook1 = xlrd.open_workbook(file)
    sheet1 = workbook1.sheet_by_index(sheet_index)
    try:
        for i in range(1, sheet1.nrows):
            G.add_edge(sheet1.row_values(i)[0],sheet1.row_values(i)[8])   #将每一行的第0列和第8列加入到图的边中
        nx.write_gml(G,'Project111111111111.txt')
    except:
        print("Unexpected error:", sys.exc_info())# sys.exc_info()返回出错信息
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
    print("可选择点的范围为:", G.nodes())
    while(True):
        source = int(input("任意选择一个点作为起始点(最短路径输出时都为点的id号):"))
        target = int(input("任意选择一个点作为终止点(最短路径输出时都为点的id号):"))
        try:
            print([p for p in nx.all_shortest_paths(G, source= source, target=target)])
        except:
            print()
        else:
            source = int(input("任意选择一个点作为起始点(最短路径输出时都为点的id号):"))
            target = int(input("任意选择一个点作为终止点(最短路径输出时都为点的id号):"))


