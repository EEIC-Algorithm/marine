N, M = map(int, input().split())
A = [int(x) for x in input().split()]
cum = [0 for _ in range(N + 1)]
for i in range(N):
    cum[i+1] = cum[i]+A[i]
index = 0
mx = -1
for i in range(N-M+1):
    res = cum[i+M]-cum[i]
    if res > mx:
        mx = res
        index = i+1
print(mx, index)
