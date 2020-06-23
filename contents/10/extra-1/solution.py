#!/usr/bin/python

import sys
import heapq


def solve():
    N, M = map(int, input().split())
    G = [[] for i in range(N)]
    for i in range(M):
        u, v, c = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append((v, 2*c))
        G[v].append((u, 2*c))
    d = [int(x) for x in input().split()]
    que = []
    for i in range(N):
        heapq.heappush(que, (d[i], i))
    while que:
        res, u = heapq.heappop(que)
        if res > d[u]:
            continue
        for nxt, cost in G[u]:
            if res+cost < d[nxt]:
                d[nxt] = res+cost
                heapq.heappush(que, (d[nxt], nxt))
    print(' '.join(map(str, d)))


T = int(sys.stdin.readline())
for _ in range(T):
    solve()
