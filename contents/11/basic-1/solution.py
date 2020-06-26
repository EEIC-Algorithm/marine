used = [0] * 55
tree = [[] for _ in range(55)]


def dfs(v,t,f):
    if v == t:
        return f
    used[v] = True
    for e in tree[v]:
        if (not used[e[0]]) and (e[1] > 0):
            d = dfs(e[0], t, min(f, e[1]))
            if d > 0:
                e[1] -= d
                tree[e[0]][e[2]][1] += d
                return d
    return 0

N,M = map(int, input().split())

for i in range(M):
    u,v,c = map(int, input().split())
    u -= 1
    v -= 1
    tree[u].append([v,c,len(tree[v])])
    tree[v].append([u,0,len(tree[u])-1])

flow = 0

while True:
    for i in range(55):
        used[i] = 0
    f = dfs(0,N-1,1e9)
    if f == 0:
        break
    flow += f
print(flow)


