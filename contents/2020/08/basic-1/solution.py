MOD = 1000000007
class Combination:
    def __init__(self, N):
        self.N = N
        fac = [1,1]
        facinv = []
        for i in range(2,N+1):
            fac.append(fac[i-1] * i % MOD)
        for i in range(0,N+1):
            facinv.append(pow(fac[i], MOD-2, MOD))
        self.fac = fac
        self.facinv = facinv
        
    def npk(self, N,K):
        if K == 0 or N == K:
            return 1
        return self.fac[N] * self.facinv[N-K] % MOD

N,K = map(int, input().split())
cb = Combination(N)
print(cb.npk(N,K))
