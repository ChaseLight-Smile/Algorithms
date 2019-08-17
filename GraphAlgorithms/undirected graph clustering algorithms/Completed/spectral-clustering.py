import numpy as np
import scipy.linalg as linalg
import networkx as nx
from sklearn.cluster import KMeans
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
        input('press enter key to exit') #这儿放一个等待输入是为了不让程序退出
    return G

def getNormLaplacian(W):
	d=[np.sum(row) for row in W]
	D=np.diag(d)
	L=D-W
	Dn=np.power(np.linalg.matrix_power(D,-1),0.5)
	Lbar=np.dot(np.dot(Dn,L),Dn)
	return Lbar

def getKSmallestEigVec(Lbar,k):
	eigval,eigvec=linalg.eig(Lbar)
	dim=len(eigval)

	dictEigval=dict(zip(eigval,range(0,dim)))
	kEig=np.sort(eigval)[0:k]
	ix=[dictEigval[k] for k in kEig]
	return eigval[ix],eigvec[:,ix]

def checkResult(Lbar,eigvec,eigval,k):
	check=[np.dot(Lbar,eigvec[:,i])-eigval[i]*eigvec[:,i] for i in range(0,k)]
	length=[np.linalg.norm(e) for e in check]/np.spacing(1)

def getCenters(data,C):  # 获得中心位置
     centers = []
     for i in range(max(C)+1):
         points_list = np.where(C==i)[0].tolist()
         centers.append(np.average(data[points_list],axis=0))
     return centers


if __name__ == '__main__':
	g = read("数据清洗4520116720190610183042流水合并.xlsx")
	print("构建图完成")
	nodeNum=len(g.nodes())
	m=nx.to_numpy_matrix(g)
	Lbar=getNormLaplacian(m)
	cluster_num=6  #请用户提供该参数值，用于确定聚类的簇数目
	kEigVal,kEigVec=getKSmallestEigVec(Lbar,cluster_num)
	checkResult(Lbar,kEigVec,kEigVal,cluster_num)

    #使用k-means分成多类
	clf = KMeans(n_clusters=cluster_num)   #该步骤之前全部正确
	s = clf.fit(np.real(kEigVec))
	# s = clf.fit(np.real(kEigVec) + np.imag(kEigVec) )
	C = s.labels_
	print(C)    #标志聚类结果
	os.system("pause")
	#centers = getCenters(m,C)
	#print(centers)   #打印laplance矩阵，验证实验结果


