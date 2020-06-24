#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[100005];
ll nums[100005];

int main(){
    int n;
    scanf(" %d",&n);
    for(int i = 0; i < n;++i) scanf(" %lld",&nums[i]);
    for(int i = 1; i < n;++i){
        dp[i] = abs(nums[i]-nums[i-1]) + dp[i-1];
        if(i > 1) dp[i] = min(dp[i],abs(nums[i]-nums[i-2])+ dp[i-2]);
    }
    printf("%lld\n",dp[n-1]);
    return 0;
}
