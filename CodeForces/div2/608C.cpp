#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    pair<int,int> nums[n];
    for(int i = 0; i < n;++i) scanf(" %d %d",&nums[i].first,&nums[i].second);
    sort(nums,nums+n);
    int dp[n];
    dp[0] = 0;
    for(int i = 1; i < n;++i){
        pair<int,int> look  = {nums[i].first-nums[i].second,0};
        int ind = lower_bound(nums,nums+n,look)-nums;
        dp[i] = i - ind;
        if(ind != 0)  dp[i] += dp[ind-1];
    }
    int ans = dp[n-1];
    for(int i = n-2,j = 1; i > -1; --i,++j)
        ans = min(ans,dp[i]+j);
    printf("%d\n",ans);
    return 0;
}
