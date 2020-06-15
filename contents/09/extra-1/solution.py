N, M, S = map(int, input().split())
S -= 1
G = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)

visited = [False]*N


def dfs(n, visited):
    visited[n] = True
    for nxt in G[n]:
        if not visited[nxt]:
            dfs(nxt, visited)


dfs(S, visited)
cnt = [0]*N
for i in range(N):
    if not visited[i]:
        canReach = [False]*N
        dfs(i, canReach)
        for j in range(N):
            if canReach[j] and not visited[j]:
                cnt[i] += 1
ve = [[cnt[i], i] for i in range(N)]
ve.sort(reverse=True)
ans = 0
for i in range(N):
    u = ve[i][1]
    if not visited[u]:
        ans += 1
        dfs(u, visited)
print(ans)
