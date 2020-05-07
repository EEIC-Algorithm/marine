#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
ll dp[110][20010] = {};

int main(){
	ll N,W;
	cin >> N >> W;
	ll w[110], v[110];
	rep(i,0,N){
		cin >> w[i] >> v[i];
	}
	rep(i,0,N+1){
		rep(j,0,200*N+1){
			dp[i][j] = 2e9;
		}
	}
	dp[0][0] = 0;

	rep(i,0,N){
		rep(j,0,200 * N + 1){
			if(j - v[i] >= 0){
				dp[i+1][j] = min(dp[i+1][j], dp[i][j - v[i]] + w[i]);
			}
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);

		}
	}
	ll ans = 0;
	rep(i,0,200*N+1){
		if(dp[N][i] <= W){
			ans = max(ans, i);
		}
	}
	cout << ans << endl;


}