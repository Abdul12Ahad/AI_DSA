def dfs(node, adj, visited, res):
    visited[node] = True
    res.append(node)

    for it in adj[node]:
        if not visited[it]:
            dfs(it, adj, visited, res)


def dfs_of_graph(V, adj, start):
    visited = [False] * (V + 1)
    res = []

    dfs(start, adj, visited, res)
    return res


V = int(input("Enter number of vertices: "))
E = int(input("Enter number of edges: "))

adj = [[] for _ in range(V + 1)]

print("Enter edges (u v):")
for _ in range(E):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

start = int(input("Enter starting vertex: "))

dfs_traversal = dfs_of_graph(V, adj, start)

print("DFS Traversal:", *dfs_traversal)
