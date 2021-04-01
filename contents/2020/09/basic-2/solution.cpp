#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)

char maze[3030][3030];
int dist[3030][3030];
bool visited[3030][3030];
const int INF = 1e9 + 1;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
using pii = pair<int, int>;
void solve()
{
    int H, W;
    cin >> H >> W;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--, sy--, gx--, gy--;
    REP(i, H)
    {
        REP(j, W) { cin >> maze[i][j]; }
    }
    REP(i, H)
    REP(j, W)
    dist[i][j] = INF;
    dist[sx][sy] = 0;

    queue<pii> que;
    que.push({sx, sy});
    visited[sx][sy] = true;
    while (!que.empty())
    {
        pii p = que.front();
        que.pop();
        int x = p.first, y = p.second;
        REP(k, 4)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && maze[nx][ny] == '.')
            {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }
    int ans = dist[gx][gy];
    assert(ans < INF);
    cout << ans << endl;
}

signed main() { solve(); }
