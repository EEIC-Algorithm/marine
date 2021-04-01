N,W = map(int, input().split())
w = []
v = []
max_v = 200
for _ in range(N):
    a,b = map(int, input().split())
    w.append(a)
    v.append(b)
INF = 2000000000
dp = [[INF] * (max_v * N+1) for _ in range(N+1)]

dp[0][0] = 0

for i in range(N):
    for j in range(max_v * N+1):
        if j - v[i] >= 0:
            dp[i+1][j] = min(dp[i+1][j], dp[i][j - v[i]] + w[i])
        dp[i+1][j] = min(dp[i+1][j], dp[i][j])

ans = 0
for i in range(max_v * N + 1):
    if dp[N][i] <= W:
        ans = max(ans, i)
print(ans)
