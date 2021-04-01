/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
struct edge{
    ll to,cap,cost,rev;
};
ll V;
vector<edge> G[4000];
ll dist[4000] = {};
ll h[4000];
ll prevv[4000];
ll preve[4000];
void add_edge(ll from,ll to,ll cap,ll cost){
	G[from].push_back({to,cap,cost,(ll)G[to].size()});
	G[to].push_back({from,0,-cost,(ll)(G[from].size()-1)});
}

ll min_cost_flow(ll s, ll t, ll f){
    ll res = 0;
    fill(h, h+V, 0);
    while(f > 0){
        priority_queue<lpair, vector<lpair>, greater<lpair> > que;
        fill(dist, dist+V, INF);
        dist[s] = 0;
        que.push({0,s});
        while(not que.empty()){
            lpair p = que.top();
            que.pop();
            ll v = p.second;
            if(dist[v] < p.first) continue;
            ll i = 0;
            for(auto &e: G[v]){
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push({dist[e.to], e.to});
                }
                i++;
            }
        }
        if(dist[t] == INF){
            return -1;
        }

        rep(v,0,V) h[v] += dist[v];

        ll d = f;
        for(ll v = t; v != s; v = prevv[v]){
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * h[t];
        for(ll v = t; v != s; v = prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }

    }
    return res;

}

void solve(){
    string T;
    cin >> T;
    ll need[30] = {};
    for(auto &e: T){
        need[e - 'a']++;
    }
    ll have[110][30] = {};
    ll N;
    cin >> N;
    string s[110];
    ll a[110];
    rep(i,0,N){
        cin >> s[i] >> a[i];
        for(auto &e: s[i]){
            have[i][e-'a']++;
        }
    }
    V = 30 + N + 10;
    ll start = 30 + N + 5, target = 30 + N + 6;
    rep(c,0,26){
        add_edge(start, c, need[c], 0);
        rep(j,0,N){
            add_edge(c, 30+j, have[j][c], 0);
        }
    }

    rep(i,0,N){
        add_edge(30+i, target, a[i], i+1);
    }
    ll res = min_cost_flow(start, target, T.size());
    print(res);


    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}