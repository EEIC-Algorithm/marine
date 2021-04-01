#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
ll dp[110][100010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    ll a[110];
    rep(i,0,N) cin >> a[i];
    dp[0][0] = 1;
    rep(i,0,N){
        rrep(j,K,0){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
            if(j + a[i] + 1 <= K+1) dp[i+1][j+a[i]+1] = (dp[i+1][j+a[i]+1] - dp[i][j] + MOD) % MOD;
        }
        rep(j,0,K+1) (dp[i+1][j+1] += dp[i+1][j]) %= MOD;
    }
	cout << dp[N][K] << endl;

}
