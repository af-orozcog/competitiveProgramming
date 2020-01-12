#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(int va,unordered_map<int,ll> &dp){
    if(va == 0) return 0;
    if(dp.count(va)) return dp[va];
    dp[va] = max((ll)va,solve(va>>1,dp)+solve(va>>2,dp)+solve(va/3,dp));
    return dp[va];
}

int main(){
    int n;
    unordered_map<int,ll> dp;
    while(scanf(" %d",&n) == 1)
        printf("%lld\n",solve(n,dp));
    return 0;
}
