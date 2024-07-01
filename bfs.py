from collections import deque

def bfs(start, adj):
    visited = [False] * len(adj)
    queue = deque([start])
    visited[start] = True

    while queue:
        node = queue.popleft()
        print (node), 
        
        for neighbor in adj[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

adj = [[1, 2], [0, 3, 4], [0, 4], [1, 5], [1, 2, 5], [3, 4]]
bfs(0, adj)

