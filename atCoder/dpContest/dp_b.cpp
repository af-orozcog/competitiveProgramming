#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[100005];
ll nums[100005];

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    for(int i = 0; i < n;++i) scanf(" %lld",&nums[i]);
    for(int i = 1; i < n;++i){
        dp[i] = abs(nums[i]-nums[i-1]) + dp[i-1];
        for(int j = 0, q = i-1; q > -1 && j < k;++j,--q)
            dp[i] = min(dp[i],abs(nums[i]-nums[q])+dp[q]);
    }
    printf("%lld\n",dp[n-1]);
    return 0;
}
