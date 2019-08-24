import numpy as np
import scipy.linalg as linalg
import networkx as nx
from sklearn.cluster import KMeans
import xlrd
import sys
import os
import collections
import matplotlib.pyplot as plt
from networkx.algorithms.bridges import bridges
from networkx.algorithms.isolate import isolates

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

class SC:
	def __init__(self, G):
		self.G_copy = G.copy()
		self.G = G

	def getNormLaplacian(self, W):
		d=[np.sum(row) for row in W]
		D=np.diag(d)
		L=D-W
		Dn=np.power(np.linalg.matrix_power(D,-1),0.5)
		Lbar=np.dot(np.dot(Dn,L),Dn)
		return Lbar

	def getKSmallestEigVec(self, Lbar,k):
		eigval,eigvec=linalg.eig(Lbar)
		dim=len(eigval)

		dictEigval=dict(zip(eigval,range(0,dim)))
		kEig=np.sort(eigval)[0:k]
		ix=[dictEigval[k] for k in kEig]
		return eigval[ix],eigvec[:,ix]

	def checkResult(self, Lbar,eigvec,eigval,k):
		check=[np.dot(Lbar,eigvec[:,i])-eigval[i]*eigvec[:,i] for i in range(0,k)]
		length=[np.linalg.norm(e) for e in check]/np.spacing(1)

	def getCenters(self, data,C):  # 获得中心位置
		 centers = []
		 for i in range(max(C)+1):
			 points_list = np.where(C==i)[0].tolist()
			 centers.append(np.average(data[points_list],axis=0))
		 return centers

	def add_group_attributes(self, G, C):   #C表示组标签
		num = 0
		nodegroup = {}

		for g in C.tolist():
			nodegroup[num] = {'group':g}
			num = num + 1
		nx.set_node_attributes(self.G_copy, nodegroup)

	def to_gml(self):
		nx.write_gml(self.G_copy, 'outputofGN.gml')

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
	g=nx.read_gml('Project111111111111.txt', label='id')

	pathlengths = []

	print("source vertex {target:length, }")
	for v in g.nodes():
		spl = dict(nx.single_source_shortest_path_length(g, v))
		print('{} {} '.format(v, spl))
		for p in spl:
			pathlengths.append(spl[p])

	print('')
	print("average shortest path length %s" % (sum(pathlengths) / len(pathlengths)))

	# histogram of path lengths
	dist = {}
	for p in pathlengths:
		if p in dist:
			dist[p] += 1
		else:
			dist[p] = 1

	print('')
	print("length #paths")
	verts = dist.keys()
	for d in sorted(verts):
		print('%s %d' % (d, dist[d]))

	print("radius: %d" % nx.radius(g))
	print("diameter: %d" % nx.diameter(g))
	print("eccentricity: %s" % nx.eccentricity(g))
	print("center: %s" % nx.center(g))
	print("periphery: %s" % nx.periphery(g))
	print("density: %s" % nx.density(g))

	nx.draw(g, with_labels=True)
	plt.show()

	# rank = nx.voterank(g)
	# print("voterank:", rank)

	# print("--------判断任意两点之间是否有路径--------")
	# node1 = int(input("节点1:"))
	# node2 = int(input("节点2:"))
	# e = nx.efficiency(g,node1,node2)
	# print("返回值e为(如果返回0 说明两点之间没有通路)：",e)
	# print("--------判断任意两点之间是否有路径--------")


	# print("--------判断图中是否有孤立点--------")
	# isolatedNodes = list(nx.isolates(g))
	# print("图中的孤立点为:", isolatedNodes)
	# print("--------判断图中是否有孤立点--------")

	# print("--------判断任意两点的共同祖先--------")
	# ancestors = nx.all_pairs_lowest_common_ancestor(g)
	# print("任意两对的祖先为:", ancestors)
	# print("--------判断任意两点的共同祖先--------")


	# print("----------发现环-----------")
	# CycleGraph = nx.DiGraph()
	# cedges = list(nx.find_cycle(g,orientation='original'))
	# print(cedges)
	# cycleEdges = []
	# t = tuple()
	# for e in cedges:
	# 	print(type(e[2]))
	# 	if e[2] == "forward":
	# 		t = e[0], e[1]
	# 		cycleEdges.append(t)
	# 	else:
	# 		t = e[1], e[0]
	# 		cycleEdges.append(t)
	# CycleGraph.add_edges_from(cycleEdges)
	# nx.draw(CycleGraph, with_labels = True)
	# plt.show()
	# print("----------发现环-----------")

	# print("--------------最小生成树--------------------")
	# T = nx.minimum_spanning_tree(g)
	# print(sorted(T.edges(data=True)))
	# G2 = nx.Graph()
	# G2.add_edges_from(sorted(T.edges(data=True)))
	# nx.draw(G2, with_labels = True)
	# plt.show()
	# print("--------------最小生成树--------------------")


	print("---边集---",list(bridges(g)))
	G1 = nx.Graph()
	G1.add_edges_from(bridges(g))
	print("桥点为:", G1.nodes())
	nx.draw(G1, with_labels = True)
	plt.show()
	print("度为0的点为:", list(isolates(g)))
	sc = SC(g)

	# 显示该图的度分布
	degree_sequence = sorted([d for n, d in g.degree()], reverse=True)
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

	# draw graph in inset
	plt.axes([0.4, 0.4, 0.5, 0.5])
	Gcc = sorted(nx.connected_component_subgraphs(g), key=len, reverse=True)[0]
	pos = nx.spring_layout(g)
	plt.axis('off')
	nx.draw_networkx_nodes(g, pos, node_size=20)
	nx.draw_networkx_edges(g, pos, alpha=0.4)
	plt.show()

	nodeNum=len(g.nodes())
	m=nx.to_numpy_matrix(g)
	Lbar=sc.getNormLaplacian(m)
	cluster_num=6  #请用户提供该参数值，用于确定聚类的簇数目
	kEigVal,kEigVec=sc.getKSmallestEigVec(Lbar,cluster_num)
	sc.checkResult(Lbar,kEigVec,kEigVal,cluster_num)

    #使用k-means分成多类
	clf = KMeans(n_clusters=cluster_num)   #该步骤之前全部正确
	s = clf.fit(np.real(kEigVec))
	# s = clf.fit(np.real(kEigVec) + np.imag(kEigVec) )
	C = s.labels_
	print(C)
	print("分组信息为:", C.tolist())    #标志聚类结果，在此种情况下有6类，分别用0,1,2,3,4,5标记
	print("对应的点为:[", end="")
	for num in g.nodes():
		print(g.nodes[num]['label'], end=",")
	print(']')
	#centers = getCenters(m,C)
	#print(centers)   #打印laplance矩阵，验证实验结果


