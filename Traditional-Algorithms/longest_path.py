def In_degree_zero():#找出入度为0的节点集合
    S=[]
    for v in range(len(Node)):#Node列表存的是节点的权值，下标才表示节点
        if In_degree(v)==0:
            S.append(v)
    return S

def In_degree(u): #找某个节点的入度
    d=0
    for v in range(len(Node)):
        if u in Next_Node(v):
            d=d+1
    return d

def Next_Node(u):
    return G[u]

def longest_path(u): #深搜求最长路径
    visited[u]=1      
    for v in Next_Node(u): 
        if visited[v]==0:   
            longest_path(v)
    Relaxed(u) 

def Relaxed(u):#求顶点u的最长路径值
    for v in Next_Node(u):
        if W[u]<W[v]+Node[u]:
            W[u]=W[v]+Node[u]
            L[u]=v #记录取得最长路径的后继结点

def Print_path(s): #打印最长路径
    print(s,end="")
    next=L[s]
    while next!=-1:
        print("->",next,end='')
        next=L[next]
    print("\n")
   
while True:
    n=int(input("请输入顶点数:"))
    m=int(input("请输入边数:"))
    s=input("请输入n个节点的权值，空格隔开：")
    Node=[int(e) for e in s.split()]#存放节点的权值
    #print(Node)
    G=dict().fromkeys([i for i in range(n)],[])#初始化一个字典存储边，以节点作为key,[]作为value
    #print(G)
    print("请输入m条边，每行两个整数u,v,用空格隔开，表示有向边u->v：")
    for i in range(m):
        L2=[int(e) for e in input().split()]
        G[L2[0]]=[L2[1]]+G[L2[0]]#用上述方式创建字典，不能使用append加入元素
    W=[Node[i] for i in range(n)]#W[u]记录起点u到任意顶点的最长路径值
    L=[-1 for i in range(n)]     #L[u]表示u取得最长路径的后继结点
    visited=[0 for i in range(n)]
    In0=In_degree_zero()
    max=0;s=-1         #max记录最长路径值，s记录最长路径的起点
    for v in In0:      #从入度为0的顶点出发求最长路径
        longest_path(v)
        if W[v]>max:   
            max=W[v]
            s=v
    print("最长路径是",W[s])
    Print_path(s)           




