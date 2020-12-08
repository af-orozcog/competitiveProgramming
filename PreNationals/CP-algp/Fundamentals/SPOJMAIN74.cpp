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
    if(n0 >= MOD) n0 -= MOD;
    n0 -= val.first;
    if(n0 < 0) n0 += MOD;
    n0 *= val.first;
    if(n0 >= MOD) n0 %= MOD;

    ll n1 = val.first*val.first;
    if(n1 >= MOD) n1 %= MOD;
    n1 += (val.second*val.second)%MOD;
    if(n1 >= MOD) n1 -= MOD;

    ll n2 = n1 + n0;
    if(n2 >= MOD) n2 -= MOD;
    if(n&1)
        return {n1,n2};
    return {n0,n1};
}


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        if(!n)
            puts("0");
        else if(n == 1)
            puts("2");
        else
            printf("%lld\n",fib(n+3ll).first);
    }
    return 0;
}
