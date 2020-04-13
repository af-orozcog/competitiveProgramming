#include<bits/stdc++.h>
using namespace std;


int n;
int dp[100][100001];
int costs[100];
int need[100];

int solve(int i, int ac){
    if(dp[i][ac] != -1) return dp[i][ac];
    if(i == n-1)
        return dp[i][ac] = (need[i] + ac + 10)*costs[i];
    int beg = need[i] + ac;
    int ans = 1000000000;
    for(int k = beg; k > 0;--k)
        ans = min(ans,(k+10)*costs[i] + solve(i+1,beg-k));
    ans = min(ans,solve(i+1,beg));
    return dp[i][ac] = ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        scanf(" %d",&n);
        for(int i = 0; i < n;++i)
            scanf(" %d %d",&need[i],&costs[i]);
        printf("%d\n",solve(0,0));
    }
    return 0;
}
