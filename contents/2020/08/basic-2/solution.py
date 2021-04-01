def isPrime(x):
    if x < 2:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    cur = 3
    while True:
        if cur * cur > x:
            break
        if x % cur == 0:
            return False
        cur += 2
    return True


Q = int(input())
num = [0] * 100010
for i in range(3,100001,2):
    if isPrime(i) and isPrime((i+1)//2):
        num[i] += 1
for i in range(0,100001):
    num[i+1] += num[i]


for _ in range(Q):
    l,r = map(int, input().split())
    print(num[r] - num[l-1])
