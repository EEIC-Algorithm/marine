N = int(input())
A = [int(x) for x in input().split()]
MAX_A = 100010
dp = [0]*MAX_A
position = [0]*MAX_A
start_index = [0]*N
max_len = 0
for i in range(N):
    if dp[A[i]-1]+1 > dp[A[i]]:
        dp[A[i]] = dp[A[i]-1]+1
        position[A[i]] = i
        max_len = max(max_len, dp[A[i]])
        if dp[A[i]] == 1:
            start_index[i] = i
        else:
            start_index[i] = start_index[position[A[i]-1]]

max_val = 0
min_val = 0
min_start_index = N
for i in range(N):
    if dp[A[i]] == max_len and min_start_index > start_index[i]:
        min_start_index = start_index[i]
        max_val = A[i]
        min_val = max_val-max_len+1

now_val = min_val
index = 0
ans = []
while now_val <= max_val:
    if A[index] == now_val:
        ans.append(index+1)
        now_val += 1
    index += 1

print(len(ans))
print(' '.join(map(str, ans)))
