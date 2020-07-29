#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1000000];
pair<ll,ll> nums[1000000];

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        for(int i = 0; i < n;++i) dp[i] = 0;
        for(int i = 0; i < n;++i)
            scanf(" %lld %lld",&nums[i].first,&nums[i].second);
        sort(nums,nums+n);
        set<pair<ll,ll>> dp2;
        ll ans = 0;
        for(int i = n-1; i > -1;--i){
            ll to = nums[i].first + nums[i].second;
            pair<ll,ll> look = {to,0ll};
            int ind = lower_bound(nums,nums+n,look)-nums;
            auto pos = dp2.lower_bound({to,0});
            if(ind == n || nums[ind].first > to){
                dp[i] = to;
                ans = max(ans,nums[i].second);
            }
            else{
                dp[i] = dp[ind];
                ans = max(ans,dp[i]-nums[i].first);
            }
            if(pos != dp2.end() && (*pos).first == to){
                dp[i] = max((*pos).second,dp[i]);
                ans = max(ans,dp[i]-nums[i].first);
            }
            auto nex = dp2.lower_bound({nums[i].first,0});

            if(nex == dp2.end() || (*nex).first != nums[i].first){
                auto ve = dp2.lower_bound({nums[i].first-nums[i].second,0});
                if(ve == dp2.end() || (*ve).first != nums[i].first-nums[i].second)
                    dp2.insert({nums[i].first-nums[i].second,nums[i].first});
            }
            else{
                ll to = (*nex).second;
                ans = max(ans,to-(nums[i].first-nums[i].second));
                auto ve = dp2.lower_bound({nums[i].first-nums[i].second,0});
                if(ve == dp2.end() || (*ve).first != nums[i].first-nums[i].second)
                    dp2.insert({nums[i].first-nums[i].second,to});
                else if(to > (*ve).second){
                    dp2.erase(ve);
                    dp2.insert({nums[i].first-nums[i].second,to});
                }
            }
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
