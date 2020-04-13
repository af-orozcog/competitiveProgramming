#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        pi nums[n];
        for(int i = 0; i < n;++i) scanf(" %lld %lld",&nums[i].first,&nums[i].second);
        ll dp[n];
        dp[n-1] = 0;
        for(int i = n-2; i > -1;--i)
            dp[i] = dp[i+1] + max(nums[i+1].first-nums[i].second,0ll);
        ll ans = dp[0] + nums[0].first;
        ll add = max(nums[0].first-nums[n-1].second,0ll);
        for(int i = 1; i < n;++i)
            ans = min(ans,nums[i].first + add + dp[i] + (dp[0]-dp[i-1]));
        printf("%lld\n",ans);
    }
    return 0;
}
