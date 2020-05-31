#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
bool isPrime(ll x){
    if(x < 2) return false;
    if(x == 2) return true;
    if(x % 2 == 0) return false;
    for(ll i = 3;i <= sqrt(x) + 1;i += 2) if(x % i == 0) return false;
    return true;
}
int main(){
    ll Q;
    cin >> Q;
    int num[100010] = {};
    for(ll i = 3; i <= 100000; i += 2){
        if(isPrime(i) && isPrime((i+1)/2)) num[i]++; 
    }
    rep(i,0,100001){
        num[i+1] += num[i];
    }
    while(Q--){
        ll l,r;
        cin >> l >> r;
        cout << num[r] - num[l-1] << endl;
        
    }

}
