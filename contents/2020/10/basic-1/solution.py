import heapq
N, M, S = map(int, input().split())
edges = [[]for _ in range(N)]
inf = 10**18
for _ in range(M):
    u, v, d = map(int, input().split())
    edges[u].append((v, d))


def dijkstra(s):

    dist = [inf]*N
    dist[s] = 0
    vs = []
    heapq.heappush(vs, (0, s))
    while len(vs):
        res, v = heapq.heappop(vs)
        if res > dist[v]:
            continue
        for nxt, cost in edges[v]:
            if res+cost < dist[nxt]:
                dist[nxt] = res+cost
                heapq.heappush(vs, (dist[nxt], nxt))
    return dist


dist = dijkstra(S)
for i in range(N):
    if dist[i] == inf:
        print("INF")
    else:
        print(dist[i])
