#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1000000007;
ll dp[2];

int main(){
    int n;
    scanf(" %d",&n);
    for(int i = 0; i < n;++i){
        if(i&1){
            dp[1] += dp[0];
            if(dp[1] >= mod) dp[1] -= mod;
            ++dp[1];
        }
        else{
            dp[0] += dp[1];
            if(dp[0] >= mod) dp[0] -= mod;
            ++dp[0];
        }
    }
    ll ans = dp[0] + dp[1];
    if(ans >= mod) ans -= mod;
    printf("%lld\n",ans);
    return 0;
}
