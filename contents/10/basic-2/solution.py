N, M = map(int, input().split())
inf = 10**18
dist = [[inf for j in range(N)]for i in range(N)]
for i in range(N):
    dist[i][i] = 0
for _ in range(M):
    u, v, d = map(int, input().split())
    dist[u][v] = min(dist[u][v], d)
for k in range(N):
    for i in range(N):
        for j in range(N):
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

Q = int(input())
for _ in range(Q):
    u, v = map(int, input().split())
    if dist[u][v] == inf:
        print("INF")
    else:
        print(dist[u][v])
