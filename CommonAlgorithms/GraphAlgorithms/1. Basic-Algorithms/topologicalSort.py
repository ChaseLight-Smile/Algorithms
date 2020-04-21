#<Python代码：拓扑排序算法>
def topological_sort(graph):
    is_visit = dict((node, False) for node in graph)
    li = []

    def dfs(graph, start_node):

        for end_node in graph[start_node]:
            if not is_visit[end_node]:
                is_visit[end_node] = True
                dfs(graph, end_node)
        li.append(start_node)

    for start_node in graph:
        if not is_visit[start_node]:
            is_visit[start_node] = True
            dfs(graph, start_node)

    li.reverse()
    return li


if __name__ == '__main__':
    graph = {
        'v1': ['v5'],
        'v2': ['v1'],
        'v3': ['v1', 'v5'],
        'v4': ['v2', 'v5'],
        'v5': [],
    }
    li = topological_sort(graph)
    print(li)
