#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 10000007;
ll modPow(ll a, ll b){
    ll ans = 1;
    a = a % mod;
    while(b){
        if(b&1) ans = ans * a % mod;
        b >>=1;
        a = a * a % mod;
    }
    return ans;
}

int main(){
    ll n,k;
    while(scanf(" %lld %lld",&n,&k) == 2 && n && k){
        ll ans = modPow(n-1,k)+modPow(n-1,k)+modPow(n,k)+modPow(n-1,n-1)+modPow(n-1,n-1)+modPow(n,n);
        if(ans >= mod) ans %= mod;
        printf("%lld\n",ans);
    }
    return 0;
}
