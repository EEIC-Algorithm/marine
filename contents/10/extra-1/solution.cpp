
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
//#pragma warning(disable : 4996)

#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#define __builtin_popcountll __popcnt64
#endif

#include <limits.h>
#include <math.h>
#include <time.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m - 1; i >= n; --i)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v, n) reverse(v, v + n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define print(x) cout << (x) << '\n'
#define pe(x) cout << (x) << " "
#define DEBUG(x) cout << #x << ": " << x << endl
#define lb(v, n) lower_bound(v.begin(), v.end(), (n))
#define ub(v, n) upper_bound(v.begin(), v.end(), (n))
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) \
    REP(i, v.size())   \
    cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b)
{
    if (a > b)
        a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b)
{
    if (a < b)
        a = b;
}
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef array<int, 3> arr3;
std::random_device rd;
std::mt19937 mt(rd());
constexpr ll MOD = 998244353;
constexpr int MAX = 500050;
const double pi = acos(-1);
constexpr double EPS = 1e-8;
constexpr ll LINF = 1e18 + 1;
constexpr int INF = 1e9 + 1;
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

struct Edge
{
    int to, cost;
};
vector<Edge> G[200020];
int d[200020];

void solve()
{
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<int> A(N);
    REP(i, N)
    {
        G[i].clear();
        d[i] = 0;
    }
    REP(i, M)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G[u].push_back({v, 2 * c});
        G[v].push_back({u, 2 * c});
    }
    REP(i, N)
    {
        cin >> A[i];
        d[i] = A[i];
    }
    priority_queue<pii, vector<pii>, greater<pii>> que;
    REP(i, N) { que.push({d[i], i}); }
    while (!que.empty())
    {
        pii p = que.top();
        que.pop();
        int pos = p.second;
        if (p.first > d[p.second])
            continue;
        for (auto e : G[pos])
        {
            if (d[e.to] > d[pos] + e.cost)
            {
                d[e.to] = d[pos] + e.cost;
                que.push({d[e.to], e.to});
            }
        }
    }
    REP(i, N) { cout << d[i] << " \n"[i == N - 1]; }
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    mt.seed((int)(time(0)));
    // while (true) test();
    int q;
    cin >> q;
    while (q--)
        solve();
}
