#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
int dp[5001][5001][2] = {};
int a[5010];

int calc(ll l, ll r, ll d){
	cout << l << " " << r << " " << d << endl;
    int &res = dp[l][r][d];
    if(~res) return res;
    res = 1e9;
    if(r - l <= 1){
        return res = 0;
    }
    if(d == 0){
        if(a[l] == a[l+1]){
            res = min(res, calc(l+1,r,0));
        }else{
            res = min(res, 1 + calc(l+1,r,0));
        }
        if(a[l] == a[r-1]){
            res = min(res, calc(l+1,r,1));
        }else{
            res = min(res, 1 + calc(l+1,r,1));
        }
    }else{
        if(a[l] == a[r-1]){
            res = min(res, calc(l,r-1, 0));
        }else{
            res = min(res, calc(l, r-1, 0) + 1);
        }
        if(a[r-2] == a[r-1]){
            res = min(res, calc(l,r-1,1));
        }else{
            res = min(res, calc(l,r-1,1) + 1);
        }

    }
    return res; 

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep(i,0,N) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    ll ans = min(calc(0,N,0), calc(0,N,1));
	cout << ans << endl;
}