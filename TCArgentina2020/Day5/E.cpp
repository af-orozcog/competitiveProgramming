#include<bits/stdc++.h>
using namespace std;

int dp[5*100005];

int main(){
    int n;
    scanf(" %d",&n);
    pair<int,int> nums[n];
    for(int i = 0; i < n;++i) scanf(" %d %d",&nums[i].first,&nums[i].second);
    sort(nums,nums+n);
    for(int i = n-1; i > -1;--i){
        pair<int,int> look = {nums[i].second+1,0};
        int ind = lower_bound(nums,nums+n,look)-nums;
        dp[i] = max(dp[i+1],dp[ind]+1);
    }
    printf("%d\n",dp[0]);
    return 0;
}
