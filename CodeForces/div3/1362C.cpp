#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    ll dp[65];
    dp[0] = 0;
    for(int i = 1; i < 65;++i){
        dp[i] = i;
        for(int j = i-1; j > 0;--j) dp[i] += dp[j];
    }
    while(t--){
        ll n;
        scanf(" %lld",&n);
        ll ans = 0;
        for(int i = 1; n; ++i){
            if(n&1) ans += dp[i];
            n = n >> 1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
