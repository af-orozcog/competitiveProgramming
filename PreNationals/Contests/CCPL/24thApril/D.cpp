#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int c,n;

bool go(int n,int m, vector<pi> &use, map<int,int> &ans, map<pi,int> &dp){
    if(m%c == 0) return true;
    if(n == use.size()) return 0;
    if(dp.count({n,m})) return dp[{n,m}];
    dp[{n,m}] = 0;
    dp[{n,m}] = go(n+1,m,use,ans,dp);
    int temp = m;
    for(int i = 0; i < use[n].second && !dp[{n,m}];++i){
        temp += use[n].first;
        if(temp >= c) temp %= c;
        ans[use[n].first]++;
        dp[{n,m}] = go(n+1,temp,use,ans,dp);
    }
    for(int i = 0; i < use[n].second && !dp[{n,m}];++i){
        --ans[use[n].first];
    }
    if(ans[use[n].first] == 0) ans.erase(use[n].first);
    return dp[{n,m}];
}

int main(){
    while(scanf(" %d %d",&c,&n) == 2){
        if(c == n && c == 0) break;
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        map<int,int> mp;
        for(int i = 0; i < n;++i) mp[nums[i]]++;
        vector<pi> use;
        for(auto &va:mp)
            use.push_back(va);
        map<pi,int> dp;
        map<int,int> ans;
        dp[{0,0}] = 0;
        int m = 0;
        for(int i = 0; i < use[0].second && !dp[{0,m}];++i){
            m += use[0].first;
            if(m >= c) m %= c;
            ans[use[0].first]++;
            dp[{0,m}] = go(1,m,use,ans,dp);
        }
        if(!dp[{0,m}]){
            puts("no sweets");
            continue;
        }
        vector<int> defAns;
        for(int i = 0; i < n && ans.size();++i){
            if(ans.count(nums[i])){
                defAns.push_back(i+1);
                --ans[nums[i]];
                if(ans[nums[i]] == 0) ans.erase(nums[i]);
            }
        }
        for(int i = 0; i < defAns.size();++i){
            if(i) printf(" %d",defAns[i]);
            else printf("%d",defAns[i]);
        }
        puts("");
    }
    return 0;
}
