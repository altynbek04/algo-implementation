def dfs(node, adj, visited):
    visited[node] = True
    print (node),

    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfs(neighbor, adj, visited)

adj = [[1, 2], [0, 3, 4], [0, 4], [1, 5], [1, 2, 5], [3, 4]]
visited = [False] * len(adj)
dfs(0, adj, visited)
