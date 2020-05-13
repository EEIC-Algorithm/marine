class RollingHash:
    def __init__(self, S):
        N = len(S)
        self.N = N
        self.base1 = 1007
        self.mod1 = 10**9 + 7
        self.hash1 = [0] * (N+1)
        self.power1 = [1] * (N+1)

        for i, e in enumerate(S):
            self.hash1[i+1] = (self.hash1[i] * self.base1 + ord(e)) % self.mod1
            self.power1[i+1] = (self.power1[i] * self.base1) % self.mod1
    
    def get(self, lv, rv):
        return (self.hash1[rv] - self.hash1[lv] * self.power1[rv-lv] % self.mod1) % self.mod1

N = int(input())
S = input()
T = S[::-1]
rh = RollingHash(S)
rh2 = RollingHash(T)
lens = 0
for i in range(1, N//2+1):
    if S[i-1] != T[i-1]:
        break
    else:
        lens = i
if lens * 2 == N:
    print(len(S))
    exit()

lv = lens
rv = N - lens - 1
max_len = 1
for i in range(rv-lv+1, 1, -1):
    half = i//2
    left_hash = rh.get(lv, lv+half)
    right_hash = rh2.get(N-1-(lv+i-1), N-1-(lv+i-half) + 1)
    if left_hash == right_hash:
        max_len = i
        break

max_len2 = 1
for i in range(rv-lv+1, 1, -1):
    half = i//2
    left_hash = rh.get(rv-i+1, rv-i+1+half)
    right_hash = rh2.get(N-1-rv,N-1-(rv-half+1)+1)
    if left_hash == right_hash:
        max_len2 = i
        break

ans = ""
if max_len >= max_len2:
    ans = S[0:lens+max_len] + S[N-lens:N]
else:
    ans = S[0:lens] + S[N-lens-max_len2:N]

print(len(ans))
