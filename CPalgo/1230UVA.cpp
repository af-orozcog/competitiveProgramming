#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll modPow(ll a, ll b,ll mod){
    a %= mod;
    ll ans = 1;
    while(b){
        if(b&1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll a,b,n;
        scanf(" %lld %lld %lld",&a,&b,&n);
        printf("%lld\n",modPow(a,b,n));
    }
    scanf(" %d",&t);
    return 0;
}
