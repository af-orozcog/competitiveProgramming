#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fact[250001];

int main(){
    ll n,m;
    scanf(" %lld %lld",&n,&m);
    ll ans = 0;
    fact[0] = 1;
    for(ll i = 1; i <= n;++i){
        fact[i] = fact[i-1]*i;
        fact[i] %= m;
        //cout << fact[i] << "\n";
    }
    for(ll i = 1; i <= n;++i){
       // cout << (((fact[i]*fact[(n-i+1)])%m)*(n-i+1))%m << "\n";
        ans += (((fact[i]*fact[(n-i+1)])%m)*(n-i+1))%m;
        ans = ans % m;
    }
    printf("%lld\n",ans);
    return 0;
}
