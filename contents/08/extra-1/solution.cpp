#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)

ll power(ll x, ll n){
    if(n == 0) return 1LL;
    ll res = power(x * x % MOD, n/2);
    if(n % 2 == 1) res = res * x % MOD;
    return res;
}


int main(){
    ll M;
    cin >> M;
    ll p[200010];
    rep(i,0,M) cin >> p[i];
    sort(p, p+M);
    vector<ll> q;
    rep(i,0,M) q.push_back(p[i]);
    q.erase(unique(q.begin(), q.end()), q.end());
    ll mul_left[200010] = {}, mul_right[200010] = {};

    map<ll,ll> mp;
    rep(i,0,M) mp[p[i]]++;
    mul_left[0] = 1;
    ll sz = q.size();
    rep(i,0,sz){
        mul_left[i+1] = mul_left[i] * (mp[q[i]] + 1) % (MOD-1);
    }
    mul_right[0] = 1;
    rep(i,0,sz){
        mul_right[i+1] = mul_right[i] * (mp[q[sz-1-i]] + 1) % (MOD-1);
    }
    ll pos[200010] = {};
    rep(i,0,sz){
        pos[q[i]] = i;
    }


    ll ans = 1;
    for(auto &e: mp){
        cout << e.first << " " << e.second << endl;
        ll r = e.second * (e.second+1) / 2;
        r %= MOD-1;
        ll ps = pos[e.first];
        ll v2 = mul_left[ps] * mul_right[sz-1-ps] % (MOD-1);
        cout << mul_left[ps] << ps << mul_right[sz-1-ps] << r << sz << endl;

        ans *= power(e.first, v2 * r % (MOD-1));
        ans %= MOD;
        cout << ans << endl;
    }
    cout << ans << endl;
}