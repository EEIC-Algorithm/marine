from collections import deque
H, W = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
sy -= 1
sx -= 1
gy -= 1
gx -= 1
A = []*H
for i in range(H):
    s = input()
    A.append(s)

DX = [0, 0, 1, -1]
DY = [1, -1, 0, 0]
INF = 10**9

d = [[INF for j in range(W)]for i in range(H)]
d[sy][sx] = 0

visited = [[False for j in range(W)]for i in range(H)]
visited[sy][sx] = True
que = deque()
que.append((sy, sx))
while que:
    y, x = que.popleft()
    for k in range(4):
        nx = x+DX[k]
        ny = y+DY[k]
        if ny >= 0 and ny < H and nx >= 0 and nx < W and A[ny][nx] != '#' and not visited[ny][nx]:
            visited[ny][nx] = True
            d[ny][nx] = d[y][x]+1
            que.append((ny, nx))

print(d[gy][gx])
