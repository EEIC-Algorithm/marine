#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)

struct Combination{
private:
    ll N;
    vector<ll> fac, facinv;

public:
    Combination(ll n){
        N = n;
        fac.push_back(1); fac.push_back(1);
        rep(i,2,N+1) fac.push_back(fac[i-1] * i % MOD);
        rep(i,0,N+1) facinv.push_back(power(fac[i], MOD-2));
    }
    ll power(ll x, ll n){
        if(n == 0) return 1LL;
        ll res = power(x * x % MOD, n/2);
        if(n % 2 == 1) res = res * x % MOD;
        return res;
    }
    ll nck(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        return fac[n] * facinv[k] % MOD * facinv[n-k] % MOD;
    }
    ll npk(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        return fac[n] * facinv[n-k] % MOD;
    }
};

int main(){
	ll N,K;
	cin >> N >> K;
	Combination cb(100010);
	ll ans = cb.npk(N,K);
	cout << ans << endl;

}