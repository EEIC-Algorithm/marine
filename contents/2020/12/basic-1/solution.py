class UnionFind:
    def __init__(self, N_):
        self.N = N_
        self.rank = [0 for i in range(self.N)]
        self.par = [i for i in range(self.N)]
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]
    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y: return
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1
    def same(self, x, y):
        return self.find(x) == self.find(y)

N, M = map(int, input().split())
edges = []
for i in range(M):
    a, b, d = map(int, input().split())
    edges.append((d, a, b))

ans = 0
uf = UnionFind(N)
edges.sort()
for e in edges:
    if not uf.same(e[1], e[2]):
        ans += e[0]
        uf.unite(e[1], e[2])

print(ans)