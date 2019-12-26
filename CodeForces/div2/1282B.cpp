#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,p,k;
        scanf(" %d %d %d",&n,&p,&k);
        int nums[n];
        for(int i = 0;i < n;++i) scanf(" %d",&nums[i]);
        sort(nums,nums+n);
        vector<int> dp(n);
        vector<int> memo(n);
        dp[0] = (nums[0]<=p);
        memo[0] = (dp[0]?p-nums[0]:p);
        for(int i = 1; i < k-1;++i){
            if(memo[i-1]-nums[i]>= 0){
                dp[i] = dp[i-1]+1;
                memo[i] = memo[i-1] - nums[i];
            }
            else{
                dp[i] = dp[i-1];
                memo[i] = memo[i-1];
            }
        }
        dp[k-1] = (p-nums[k-1] >= 0? k:dp[k-2]);
        if(dp[k-1] == k) memo[k-1] = p-nums[k-1];
        else memo[k-1] = memo[k-2];
        for(int i = k; i < n;++i){
            dp[i] = dp[i-1];
            memo[i] = memo[i-1];
            if(memo[i-k]-nums[i] >= 0){
                if(dp[i-1] < dp[i-k]+k){
                    dp[i] = dp[i-k]+k;
                    memo[i] = memo[i-k]-nums[i];
                }
            }
        }
        printf("%d\n",dp[n-1]);
    }
    return 0;
}
