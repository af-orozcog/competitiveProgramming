#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

ll MOD = 1000000007;

pi fib(ll n){
    if(!n)
        return {0,1};
    pi val = fib(n>>1);
    ll n0 = val.second<<1;
    if(n0 >= MOD)
        n0 -= MOD;
    n0 -= val.first;
    if(n0 < 0) n0 += MOD;
    n0 *= val.first;
    if(n0 >= MOD) n0 %= MOD;

    ll n1 = (val.first*val.first);
    if(n1 >= MOD) n1 %= MOD;
    n1 += (val.second*val.second)%MOD;
    if(n1 >= MOD) n1 -= MOD;

    ll n2 = n1 + n0;
    if(n2 >= MOD) n2 -= MOD;

    if(n&1)
        return {n1,n2};
    return {n0,n1};
}


ll sumUpTo(ll n){
    return fib(n+2).first-1ll;
}


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll a,b;
        scanf(" %lld %lld",&a,&b);
        ll show = sumUpTo(b) - (a != 0? sumUpTo(a-1):0);
        if(show < 0) show += MOD;
        printf("%lld\n",show);
    }
    return 0;
}
