#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    char see[n+1];
    scanf(" %s",see);
    int dp[n];
    dp[0] = (see[0] == '0'?-1:1);
    unordered_map<int,int> memo;
    memo[dp[0]] = 0;
    for(int i = 1; i < n;++i){
        if(see[i] == '1') dp[i] = dp[i-1] +1;
        else dp[i] = dp[i-1] -1;
        if(!memo.count(dp[i])) memo[dp[i]] = i;
        else memo[dp[i]] = max(i,memo[dp[i]]);
    }
    int ans = 0;
    for(int i = 0; i < n;++i){
        ans = max(ans,memo[dp[i]] -i);
        if(dp[i] == 0) ans = max(ans,i+1);
    }
    printf("%d\n",ans);
    return 0;
}
