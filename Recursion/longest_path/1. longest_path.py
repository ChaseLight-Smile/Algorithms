class AdjListNode:

    def __init__(self, _v, _w):
        self.v = _v
        self.weight = _w

    def getV(self):
        return self.v

    def getWeight(self):
        return self.weight


class Graph:

    def __init__(self, V):
        self.V = V
        self.adj = [[] for i in range(V)]
        self.max_paths = [[] for i in range(V)]
        self.max_value = [[] for i in range(V)]
    def addEdge(self, u, v, weight):
        node = AdjListNode(v, weight)

        self.adj[u].append(node)


    def topologicalSortUtil(self, v, visited, stack):
        # 标记当前顶点为已访问
        visited[v] = True

        # 对所有邻接点执行递归调用
        for node in self.adj[v]:
            if not visited[node.getV()]:
                self.topologicalSortUtil(node.getV(), visited, stack)

        # 当某个点没有邻接点时，递归结束，将该点存入栈中。
        stack.append(v)


    def longestPath(self, s):
        stack = []
        visited = [False for i in range(self.V)]
        dist = [-float('inf') for i in range(self.V)]
        # 对每个顶点调用topologicalSortUtil，最终求出图的拓扑序列存入到Stack中。
        for i in range(len(visited)):
            if not visited[i]:
                self.topologicalSortUtil(i, visited, stack)

        # 初始化到所有顶点的距离为负无穷
        # 到源点的距离为0
        dist[s] = nodes[s]
        size = len(stack)
        # 处理拓扑序列中的点
        while size != 0:
            # 取出拓扑序列中的第一个点
            u = stack[size - 1]
            size -= 1
            # 更新到所有邻接点的距离
            if dist[u] != -float('inf'):
                for i in self.adj[u]:
                    if dist[i.getV()] < dist[u] + i.getWeight():
                        dist[i.getV()] = dist[u] + i.getWeight()
        self.stack = stack
        for i in range(self.V):
            if dist[i] == -float('inf'):
                # print("INF ", end='')
                pass
            else:
                self.max_paths[s].append(str(i))
                self.max_value[s].append(dist[i])
                # print(str(s),":",self.max_paths[s], self.max_value[s])


num_node = input("请输入节点个数:")
num_node = int(num_node)
g = Graph(num_node)

print("请输入权重，每行一个")
nodes = []
for i in range(num_node):
    node_wight_str = input()
    nodes.append(int(node_wight_str))      # (index, weight)


print("请输入边(v1 v2),输入-1 -1结束:")


max_value = 0
max_path = []
while True:
    edge_info = input()
    edge_str = edge_info.split(" ")
    if edge_str[0] == "-1" and edge_str[1] == "-1":
        for s in range(num_node):
            g.longestPath(s)
            if max_value < max(g.max_value[s]):
                max_value = max(g.max_value[s])
                index = g.max_value[s].index(max_value)
                max_path = g.max_paths[s][0:index+1]
                # print("max:", max_value, max_path)

        break
    g.addEdge(int(edge_str[0]), int(edge_str[1]), nodes[int(edge_str[1])])


fixed_max_path = []

for node in g.stack[::-1]:
    if str(node) in max_path:
        fixed_max_path.append(str(node))


print("路径:", "->".join(fixed_max_path))
print("最长路径权值:", max_value)
