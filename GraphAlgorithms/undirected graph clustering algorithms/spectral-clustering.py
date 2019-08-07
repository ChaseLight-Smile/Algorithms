import numpy as np
import scipy.linalg as linalg
import networkx as nx
from sklearn.cluster import KMeans


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
	g=nx.read_gml('karate.gml',label='id')

	nodeNum=len(g.nodes())
	m=nx.to_numpy_matrix(g)
	Lbar=getNormLaplacian(m)
	cluster_num=4   #请用户提供该参数值，用于确定聚类的簇数目
	kEigVal,kEigVec=getKSmallestEigVec(Lbar,cluster_num)
	checkResult(Lbar,kEigVec,kEigVal,cluster_num)

    #使用k-means分成多类
	clf = KMeans(n_clusters=cluster_num)
	s = clf.fit(kEigVec)
	C = s.labels_
	print(C)    #标志聚类结果

	#centers = getCenters(m,C)
	#print(centers)   #打印laplance矩阵，验证实验结果


