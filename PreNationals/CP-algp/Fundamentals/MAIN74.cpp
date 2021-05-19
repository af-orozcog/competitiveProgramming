#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pl;

ll MOD = 1000000007;

pl fib(ll n){
    if(n == 0)
        return {0,1};
    pl imp = fib(n/2);
    ll first = imp.second<<1;
    if(first >= MOD) first -= MOD;
    first -= imp.first;
    if(first < 0) first += MOD;
    first *= imp.first;
    if(first >= MOD) first %= MOD;
    ll second = imp.first*imp.first;
    if(second >= MOD) second %= MOD;
    second += (imp.second*imp.second) % MOD;
    if(second >= MOD) second -= MOD;
    if(n % 2 == 0)
        return {first,second};
    else{
        ll see = first+second;
        if(see >= MOD) see -= MOD;
        return {second,see};
    }
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        if(n == 0) puts("0");
        else if(n == 1) puts("2");
        else printf("%lld\n",fib(n+3).first);
    }
    return 0;
}
