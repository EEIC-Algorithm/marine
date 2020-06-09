N, M, S, T = map(int, input().split())
S -= 1
T -= 1
G = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

visited = [False]*N


def dfs(n, visited):
    visited[n] = True
    for nxt in G[n]:
        if not visited[nxt]:
            dfs(nxt, visited)


dfs(S, visited)
if visited[T]:
    print("Yes")
else:
    print("No")
