#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll modPow(ll a, ll b, ll mod){
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
    ll a,b,mod;
    while(scanf(" %lld %lld %lld",&a,&b,&mod) == 3)
        printf("%lld\n",modPow(a,b,mod));
    return 0;
}
