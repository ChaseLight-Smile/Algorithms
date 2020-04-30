import numpy as np
import networkx as nx
from sklearn.cluster import SpectralClustering
from sklearn import metrics
import xlrd
import sys
import os
np.random.seed(1)


def read(file, sheet_index=0):
	G = nx.Graph()
	workbook1 = xlrd.open_workbook(file)
	sheet1 = workbook1.sheet_by_index(sheet_index)
	try:
		for i in range(1, sheet1.nrows):
			G.add_edge(sheet1.row_values(i)[0],sheet1.row_values(i)[8], group = 0)   #将每一行的第0列和第8列加入到图的边中
		 # 给每个节点增加标签
		nx.write_gml(G, "Project111111111111.txt")
	except:
		print("Unexpected error:", sys.exc_info())# sys.exc_info()返回出错信息
		input('press enter key to exit') #这儿放一个等待输入是为了不让程序退出
	return G

if __name__ == "__main__":
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
    G=nx.read_gml('Project111111111111.txt', label='id')

    # Get ground-truth: club-labels -> transform to 0/1 np-array
    #     (possible overcomplicated networkx usage here)
    gt_dict = nx.get_node_attributes(G, 'label')
    gt = [gt_dict[i] for i in G.nodes()]
    gt = np.array([0 if i == 'Mr. Hi' else 1 for i in gt])

    # Get adjacency-matrix as numpy-array
    adj_mat = nx.to_numpy_matrix(G)

    print('ground truth')
    print(gt)

    # Cluster
    sc = SpectralClustering(5, affinity='precomputed', n_init=100)
    sc.fit(adj_mat)

    # Compare ground-truth and clustering-results
    print('spectral clustering')
    print(sc.labels_)
    print('just for better-visualization: invert clusters (permutation)')
    print(np.abs(sc.labels_ - 1))

    # Calculate some clustering metrics
    print(metrics.adjusted_rand_score(gt, sc.labels_))
    print(metrics.adjusted_mutual_info_score(gt, sc.labels_))
