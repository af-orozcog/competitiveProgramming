#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll go(ll n, map<ll,ll> &dp){
    if(n == 0) return 0;
    if(dp.count(n)) return dp[n];
    ll ans = max(n,go(n/2,dp)+go(n/3,dp)+go(n/4,dp));
    return dp[n] = ans;
}

int main(){
    ll n;
    map<ll,ll> dp;
    while(scanf(" %lld",&n) == 1)
        printf("%lld\n",go(n,dp));
    return 0;
}
