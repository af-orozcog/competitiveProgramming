#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll raise(int to, ll ra){
    ll ans = 1;
    for(int i = 0; i < to;++i)
        ans *= ra;
    //printf("%lld\n",ans);
    return ans;
}

int dp[1002];

int main(){
    dp[0] = 1;
    ll x,n;
    scanf(" %lld %lld",&x,&n);
    vector<ll> nums;
    ll i = 1;
    while(raise(n,i) <= x){
        nums.push_back(raise(n,i));
        //printf("%d\n",nums.back());
        ++i;
    }
    for(ll i = 0; i < (ll)nums.size();++i){
        for(ll j = 1001; j > -1;--j){
            if(nums[i]+j < 1002)
                dp[nums[i]+j] += dp[j];
        }
    }
    printf("%d\n",dp[x]);
    return 0;
}
