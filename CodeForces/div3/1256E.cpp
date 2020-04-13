#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
   int n;
   scanf(" %d",&n);
   pair<ll,int> nums[n+1];
   for(int i = 1; i <= n;++i){
        scanf(" %lld",&nums[i].first);
        nums[i].second = i;
   }
   nums[0].first = nums[0].second = 0;
   sort(nums,nums+n+1);
   ll dp[n+1];
   for(int i = 0; i <= n;++i) dp[i] = 1000000000000ll;
   dp[0] = 0;
   dp[3] = nums[3].first - nums[1].first;
   for(int i = 4; i <= n;++i){
        for(int j = 3;j < 6;++j){
            if(i - j > -1)
                dp[i] = min(dp[i],dp[i-j] + nums[i].first - nums[i-j+1].first);
        }
   }
   int i = n;
   vector<int> vals;
   while(i){
       ll comp = 1000000000000ll;
       int who;
       for(int j = 3;j < 6;++j){
            if(i - j > -1 && dp[i-j] + nums[i].first - nums[i-j+1].first < comp)
                comp = dp[i-j] + nums[i].first - nums[i-j+1].first, who = i-j;
       }
       i = who;
       vals.push_back(i);
   }
   reverse(vals.begin(),vals.end());
   int ans[n+1];
   int teams = 1;
   for(int i = n; i > 0;--i){
        if(i == vals.back()){++teams;vals.pop_back();}
        ans[nums[i].second] = teams;
   }
   printf("%lld %d\n",dp[n],teams);
   for(int i = 1; i <= n;++i) printf("%d ",ans[i]);
   puts("");
   return 0;
}
