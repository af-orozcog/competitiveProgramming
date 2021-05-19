#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll INF = 100000000000000LL;


int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    ll dp[n];
    ll nums[n];
    for(int i = 0; i < n;++i) scanf(" %lld",&nums[i]);
    for(int i = 0; i < n;++i) dp[i] = INF;
    dp[n-1] = 0;
    for(int i = n-2; i > -1;--i){
        for(int j = i+1,co = 0; j < n && co < k;++j,++co)
            dp[i] = min(dp[i], dp[j] + abs(nums[i]-nums[j]));
    }
    printf("%lld\n",dp[0]);
    return 0;
}
