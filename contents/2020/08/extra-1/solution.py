M = int(input())
p = list(map(int, input().split()))
MOD = 1000000007

p.sort()
q = []
for i in range(M):
    q.append(p[i])
q = list(set(q))
mul_left = [0] * 200010
mul_right = [0] * 200010

mp = {}
for i in range(M):
    if p[i] not in mp:
        mp[p[i]] = 1
    else:
        mp[p[i]] += 1

mul_left[0] = 1
mul_right[0] = 1

for i in range(len(q)):
    mul_left[i+1] = mul_left[i] * (mp[q[i]] + 1) % (MOD-1)
    mul_right[i+1] = mul_right[i] * (mp[q[len(q)-1-i]] + 1) % (MOD-1)

pos = [0] * 200010
for i in range(len(q)):
    pos[q[i]] = i

ans = 1
for key, val in mp.items():
    r = val * (val+1) // 2
    r %= MOD-1
    ps = pos[key]
    ans *= pow(key, mul_left[ps] * mul_right[len(q)-1-ps] * r % (MOD-1), MOD)
    ans %= MOD
print(ans)