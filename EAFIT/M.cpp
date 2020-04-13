#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll vals[21];
ll n,k;

ll solve(ll va, unordered_map<ll,int> &dp){
    if(va > n) return 1000000000;
    if(va == n) return 0;
    if(dp.count(va)) return dp[va];
    ll ans = 1000000000;
    for(int i = 0; i < k;++i)
        ans = min(ans,1ll + solve(va*vals[i],dp));
    return dp[va] = ans;
}

vector<ll> ans;

void get(ll va,int tar, unordered_map<ll,int> &dp){
    if(tar < 0) return;
    if(va == n){ans.push_back(va);return;}
    ll mi = 1000000000;
    for(int i = 0; i < k;++i){
        if(dp[va*vals[i]] == tar && va*vals[i] < mi)
            mi = va*vals[i];
    }
    ans.push_back(mi);
    get(mi,tar-1,dp);
}

int main(){
    scanf(" %lld %lld",&n,&k);
    for(int i = 0; i < k;++i) scanf(" %lld",&vals[i]);
    unordered_map<ll,int> dp;
    ll anss = solve(1ll,dp);
    if(anss == 1000000000ll){
        puts("-1");return 0;
    }
    ans.push_back(1);
    get(1,anss-1,dp);
    for(auto va:ans) printf("%d ",va);
    puts("");
    return 0;
}
