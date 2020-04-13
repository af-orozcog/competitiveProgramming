#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,pair<ll,ll>> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        pi nums[n];
        for(int i = 0; i < n;++i) scanf(" %lld %lld %lld",&nums[i].first,&nums[i].second.first,&nums[i].second.second);
        sort(nums,nums+n);
        int dp[n];
        dp[n-1] = nums[n-1].second.second;
        for(int i = n-2; i > -1;--i){
            pi look = {nums[i].first+nums[i].second.first,{0,0}};
            int inde = lower_bound(nums,nums+n,look)-nums;
            dp[i] = nums[i].second.second;
            if(inde != n)
                dp[i] += dp[inde];
            dp[i] = max(dp[i],dp[i+1]);
        }
        printf("%d\n",dp[0]);
    }
    return 0;
}
