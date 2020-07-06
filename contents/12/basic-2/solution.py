import heapq
N, M = map(int, input().split())
added = [False]*N
G = [[]for i in range(N)]
for i in range(M):
    a, b, d = map(int, input().split())
    G[a].append((d, b))
    G[b].append((d, a))
ans = 0

cnt = 1
added[0] = True
edges = []
for e in G[0]:
    heapq.heappush(edges,e)
while cnt < N:
    while edges:
        d, nxt = heapq.heappop(edges)
        if not added[nxt]:
            cnt+=1
            added[nxt] = True
            ans += d
            for e in G[nxt]:
                heapq.heappush(edges, e)
            break
print(ans)