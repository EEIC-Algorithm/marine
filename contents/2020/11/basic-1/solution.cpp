#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)

typedef struct {
    ll to;
    ll cap;
    ll rev;
} edge;

ll used[110] = {};
vector<edge> tree[110];

ll dfs(ll v, ll t, ll f){
    if(v == t) return f;
    used[v] = true;
    for(auto &e: tree[v]){
        if(!used[e.to] && e.cap > 0){
            ll d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                tree[e.to][e.rev].cap += d;
                return d;
            }
        }

    }
    return 0;
}

int main(){
    int N,M;
    cin >> N >> M;
    
    rep(i,0,M){
        ll u,v,c;
        cin >> u >> v >> c;
        u--; v--;
        tree[u].push_back({v, c, (ll) tree[v].size()});
        tree[v].push_back({u, 0LL, (ll)(tree[u].size() - 1)});
    }
    ll flow = 0;
    while(true){
        memset(used, 0, sizeof(used));
        ll f = dfs(0, N-1, INF);
        if(f == 0) break;
        flow += f;
    }
    cout << flow << endl;

}