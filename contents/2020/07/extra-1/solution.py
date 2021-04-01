dp = [[[-1] * 3 for _ in range(2001)] for _ in range(2001)]

def calc(l, r, d):
    res = dp[l][r][d]
    if res != -1:
        return res
    res = 1000000000
    
    if r - l <= 1:
        res = dp[l][r][d] = 0
        return res

    if d == 0:
        if a[l] == a[l+1]:
            res = min(res, calc(l+1, r, 0))
        else:
            res = min(res, 1 + calc(l+1, r, 0))
        
        if a[l] == a[r-1]:
            res = min(res, calc(l+1, r, 1))
        else:
            res = min(res, 1 + calc(l+1, r, 1))
    else:
        if a[l] == a[r-1]:
            res = min(res, calc(l, r-1, 0))
        else:
            res = min(res, 1 + calc(l, r-1, 0))
        
        if a[r-2] == a[r-1]:
            res = min(res, calc(l, r-1, 1))
        else:
            res = min(res, 1 + calc(l, r-1, 1))
    
    dp[l][r][d] = res
    return res;


N = int(input())
a = list(map(int,input().split()))

ans = min(calc(0,N,0), calc(0,N,1))
print(ans)
