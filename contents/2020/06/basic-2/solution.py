N, W = map(int, input().split())
dp = [[0]*(W+1) for _ in range(N+1)]
w = [0]*N
v = [0]*N
for i in range(N):
    a, b = map(int, input().split())
    w[i] = a
    v[i] = b

for i in range(N):
    for j in range(W+1):
        dp[i+1][j] = max(dp[i+1][j], dp[i][j])
        if(j+w[i] <= W):
            dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j]+v[i])

ans = 0
for j in range(W+1):
    ans = max(ans, dp[N][j])
print(ans)
