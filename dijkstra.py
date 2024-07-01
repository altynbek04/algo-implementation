import heapq

INF = float('inf')

def dijkstra(start, adj):
    dist = [INF] * len(adj)
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        d, node = heapq.heappop(pq)

        if d != dist[node]:
            continue

        for next_node, weight in adj[node]:
            if dist[node] + weight < dist[next_node]:
                dist[next_node] = dist[node] + weight
                heapq.heappush(pq, (dist[next_node], next_node))

    for i, d in enumerate(dist):
        print("Distance to node {} is {}".format(i, d))

adj = [
    [(1, 2), (2, 4)], [(0, 2), (2, 1), (3, 7)], [(0, 4), (1, 1), (3, 3)], [(1, 7), (2, 3)]
]
dijkstra(0, adj)
