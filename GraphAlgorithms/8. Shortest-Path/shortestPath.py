from tkinter import *
import tkinter.messagebox
from PIL import Image,ImageTk
import networkx as nx
import matplotlib.pyplot as plt
import time

MAX_NUM=100000
sleep_time=0.1
#demo
"""
0,10,inf,inf,inf,9,15;
10,0,inf,inf,inf,2,inf;
inf,inf,0,inf,1,inf,10;
inf,inf,inf,0,7,inf,inf;
inf,inf,1,7,0,inf,12;
9,2,inf,inf,inf,0,3;
15,inf,10,inf,12,3,0
"""

"""
0,6,3,inf,inf,inf;
6,0,2,5,inf,inf;
3,2,0,3,4,inf;
inf,5,3,0,2,3;
inf,inf,4,2,0,5;
inf,inf,inf,3,5,0
"""

root = Tk()
root.title("path")
root.geometry('1290x600')                 #是x 不是*    '1000x600'
#root.resizable(width=True, height=True) #宽不可变, 高可变,默认为True

#algrithm
#dij
#http://www.cnblogs.com/biyeymyhjob/archive/2012/07/31/2615833.html
#http://blog.csdn.net/littlethunder/article/details/9748519
def dij(arraylist,start,n):
    dis = [0]*n
    flag = [False]*n
    pre = [start]*n
    points = []
    k = start
    flag[k]=True
    for i in range(n):
        dis[i] = arraylist[k][i]
    for i in range(n-1):
        mini = MAX_NUM
        for j in range(n):
            if not flag[j] and dis[j]<mini:
                mini = dis[j]
                k = j
        if k==start:#不连通
            return
        flag[k] = True
        for j in range(n):
            if dis[j]>dis[k]+arraylist[k][j]:
                dis[j] = dis[k]+arraylist[k][j]
                pre[j] = k
        points.append(k)
    dist = []
    path = []
    for point in points:
        dist.append(dis[point])
        path_point = []
        while(pre[point]!=start):
            path_point.insert(0,(pre[point],point))
            point = pre[point]
        path_point.insert(0,(start,point))
        path.append(path_point)
    return points,dist,path

#Floyd
def floyd(arraylist,start,n):
    dis = arraylist
    path_points = []#存放点之间经过的点
    for i in range(n):
        pp = []
        for j in range(n):
            pp.append([])
        path_points.append(pp)
    for k in range(n):#i经过k到j
        for i in range(n):
            for j in range(n):
                if k==i or k==j:
                    continue
                if dis[i][j]>arraylist[i][k]+arraylist[k][j]:
                    dis[i][j] = dis[i][k] + dis[k][j]
                    tmp = []
                    for item in path_points[i][k]:
                        tmp.append(item)
                    tmp.append(k)
                    for item in path_points[k][j]:
                        tmp.append(item)
                    path_points[i][j] = tmp
    points=[]
    dist=[]
    path=[]
    for i in range(n):
        if i==start:
            continue
        points.append(i)
        dist.append(dis[start][i])
        if len(path_points[start][i])==0:#不经过其他点
            path.append([(start,i)])
        else:
            tmp = []
            for j in range(len(path_points[start][i])-1):
                tmp.append((path_points[start][i][j],path_points[start][i][j+1]))
            tmp.insert(0,(start,path_points[start][i][0]))
            tmp.append((path_points[start][i][-1],i))
            path.append(tmp)
    return points,dist,path

#Bellman-Ford
#http://blog.csdn.net/xu3737284/article/details/8973615
def bellmanFord(arraylist,start,n,e):
    dis = [0]*n
    path_points = []
    for i in range(n):
        path_points.append([])
    #初始化
    for i in range(n):
        if i!=start:
            dis[i] = MAX_NUM
    for i in range(len(e)):
        if e[i][0]==start:
            dis[e[i][1]] = e[i][2]
    for i in range(n-1):
        for j in range(len(e)):
            if dis[e[j][1]]>dis[e[j][0]]+e[j][2]:
                dis[e[j][1]] = dis[e[j][0]]+e[j][2]
                tmp = []
                for item in path_points[e[j][0]]:
                    tmp.append(item)
                tmp.append(e[j][0])
                path_points[e[j][1]] = tmp
    points=[]
    dist=[]
    path=[]
    for i in range(n):
        if i==start:
            continue
        points.append(i)
        dist.append(dis[i])
        if len(path_points[i])==0:#不经过其他点
            path.append([(start,i)])
        else:
            tmp = []
            for j in range(len(path_points[i])-1):
                tmp.append((path_points[i][j],path_points[i][j+1]))
            tmp.insert(0,(start,path_points[i][0]))
            tmp.append((path_points[i][-1],i))
            path.append(tmp)
    return points,dist,path

#处理
def sel():
   selection = "You selected the option " + str(var.get())
   print(selection)
   algorithm = var.get()
   return algorithm
def startPro():
    print("start....")
    t6.delete('0.0', END)
    sampleInput = t2.get("0.0",END)
    print(sampleInput)
    sampleInput = sampleInput.replace('\n','').split(';')
    arraylist = []
    for item in sampleInput:
        arraylist_col=[]
        item = item.split(',')
        for item2 in item:
            if item2!="inf":
                item2 = re.sub("\D", "", item2)
                arraylist_col.append(int(item2))
            else:
                arraylist_col.append(MAX_NUM)
        if len(arraylist_col)>0:
            arraylist.append(arraylist_col)
    for item in arraylist:
        if len(arraylist)!=len(item):
            tkinter.messagebox.showinfo("Error","请检查输入的邻接矩阵！")
            return
    n = len(arraylist)
    start = int(e4.get())
    if(start>=len(arraylist)):
        tkinter.messagebox.showinfo("Error","起始点不能大于点的总数！")
        return
    
    #建图
    plt.clf()
    G = nx.Graph()
    e=[]
    ew = {}
    for i in range(0,len(arraylist)):
        for j in range(0,len(arraylist[i])):
            if arraylist[i][j]<MAX_NUM:
                e.append((i,j,arraylist[i][j]))
                ew[(i,j)] = arraylist[i][j]
    G.add_weighted_edges_from(e)
    pos = nx.spring_layout(G)
    nx.draw(G, pos, with_labels = True, node_size = 500 ,hold=True,node_color ='w')
    nx.draw_networkx_edge_labels(G,pos,ew)
    nx.draw_networkx_nodes(G,pos,nodelist=[start],node_color ='b',node_size = 700)
    plt.savefig('path' +'.jpg')
    filename = ".\path.jpg"
    image = Image.open(filename)
    photo = ImageTk.PhotoImage(image)
    canvas.create_image(450,250,image = photo)
    canvas.update()
    time.sleep(sleep_time)
    
    algorithm=0
    algorithm = sel()
    if algorithm==0:
        tkinter.messagebox.showinfo("Error","请先选择需要使用的算法!")
        return
    elif algorithm==1:#dij
        points,dist,path = dij(arraylist,start,n)
        for i in range(0,len(points)):
            print(points[i])
            str_path = str(start)
            for j in range(len(path[i])):
                str_path = str_path + '->' + str(path[i][j][1])
            print(str_path)
            t6.insert(END,str_path+"\n")
            nx.draw_networkx_nodes(G,pos,nodelist=[points[i]],node_color = 'g',node_size = 600)
            nx.draw_networkx_edges(G,pos,edgelist=path[i],width=6,edge_color = 'red')
            plt.savefig('path' +'.jpg')
            filename = ".\path.jpg"
            image = Image.open(filename)
            photo = ImageTk.PhotoImage(image)
            canvas.create_image(450,250,image = photo)
            canvas.update()
            time.sleep(sleep_time)
    elif algorithm==2:#Floyd
        points,dist,path = floyd(arraylist,start,n)
        for i in range(0,len(points)):
            print(points[i])
            str_path = str(start)
            for j in range(len(path[i])):
                str_path = str_path + '->' + str(path[i][j][1])
            print(str_path)
            t6.insert(END,str_path+"\n")
            nx.draw_networkx_nodes(G,pos,nodelist=[points[i]],node_color = 'g',node_size = 600)
            nx.draw_networkx_edges(G,pos,edgelist=path[i],width=6,edge_color = 'red')
            plt.savefig('path' +'.jpg')
            filename = ".\path.jpg"
            image = Image.open(filename)
            photo = ImageTk.PhotoImage(image)
            canvas.create_image(450,250,image = photo)
            canvas.update()
            time.sleep(sleep_time)
    elif algorithm==3:#Bellman-Ford
        points,dist,path = bellmanFord(arraylist,start,n,e)
        for i in range(0,len(points)):
            print(points[i])
            str_path = str(start)
            for j in range(len(path[i])):
                str_path = str_path + '->' + str(path[i][j][1])
            print(str_path)
            t6.insert(END,str_path+"\n")
            nx.draw_networkx_nodes(G,pos,nodelist=[points[i]],node_color = 'g',node_size = 600)
            nx.draw_networkx_edges(G,pos,edgelist=path[i],width=6,edge_color = 'red')
            plt.savefig('path' +'.jpg')
            filename = ".\path.jpg"
            image = Image.open(filename)
            photo = ImageTk.PhotoImage(image)
            canvas.create_image(450,250,image = photo)
            canvas.update()
            time.sleep(sleep_time)
    time.sleep()


#frame容器
frame_top = Frame(width=1190, height=50)
frame_r1 = Frame(width=260,height=50)
frame_r2 = Frame(width=260,height=150,bg='white')
frame_r3 = Frame(width=260,height=50)
frame_r4 = Frame(width=260,height=50)
frame_r5 = Frame(width=260,height=50)
frame_r6 = Frame(width=260,height=150,bg='white')
frame_l1 = Frame(width=130, height=50)
frame_l2 = Frame(width=130, height=50)
frame_l3 = Frame(width=130, height=50)
frame_mid = Frame(width=900,height=500,bg='white')
frame_bottom = Frame(width=1290,height=50)

#使用grid设置各个容器位置
frame_top.grid(row=0, column=0,columnspan=3, padx=460, pady=5)
frame_l1.grid(row=3,column=0)
frame_l2.grid(row=4,column=0)
frame_l3.grid(row=5,column=0)
frame_mid.grid(row=1,column=1,rowspan=6,padx=4, pady=5)
frame_r1.grid(row=1,column=2,sticky=W)
frame_r2.grid(row=2,column=2,padx=2, pady=5)
frame_r3.grid(row=3,column=2,sticky=W)
frame_r4.grid(row=4,column=2,sticky=W)
frame_r5.grid(row=5,column=2,sticky=W)
frame_r6.grid(row=6,column=2,padx=2, pady=5)
frame_bottom.grid(row=7,column=0,columnspan=3)


#创建需要的元素
l_title = Label(frame_top, text="Shortest Path", font=('Arial', 20))
var = IntVar()
R1 = Radiobutton(frame_l1, text="Dijkstr", variable=var, value=1,command=sel)
R2 = Radiobutton(frame_l2, text="Floyd  ", variable=var, value=2,command=sel)
R3 = Radiobutton(frame_l3, text="Bellman", variable=var, value=3,command=sel)

canvas = Canvas(frame_mid,width = 900,height = 500,bg = 'white')
#filename = ".\path.jpg"
#image = Image.open(filename)
#photo = ImageTk.PhotoImage(image)
#canvas.create_image(450,250,image = photo)
#canvas.update()

l_r1 = Label(frame_r1, text="邻接矩阵")
l_r3 = Label(frame_r3, text="起始点")
l_r5 = Label(frame_r5, text="打印路径")
vart4 = IntVar()
e4 = Entry(frame_r4, textvariable = vart4,width = 40)
#t2 = Entry(frame_r2)
#t6 = Entry(frame_r6)
t2 = Text(frame_r2,width = 40,height = 13)
t6 = Text(frame_r6,width = 40,height = 13)
button_start = Button(frame_bottom,text="Start",command=startPro)


#把元素填充进frame
l_title.grid()
R1.grid(sticky=E)
R2.grid(sticky=E)
R3.grid(sticky=E)
canvas.grid()
l_r1.grid(sticky=E)
l_r3.grid(sticky=E)
l_r5.grid(sticky=E)
t2.grid()
e4.grid()
t6.grid()
button_start.grid()

mainloop()
