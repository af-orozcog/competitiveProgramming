#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1000000007;

ll dp[2001][2001];

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    for(int i = 1; i <= n;++i){
        dp[i][1] = 1;
    }
    for(int i = 1; i < k;++i){
        for(int j = 1; j <= n;++j){
            int q = 1;
            while(j*q <= n){
                dp[j*q][i+1] += dp[j][i];
                if(dp[j*q][i+1] >= mod)
                    dp[j*q][i+1] -= mod;
                ++q;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= n;++i){
        ans += dp[i][k];
        if(ans >= mod)
            ans -= mod;
    }
    printf("%lld\n",ans);
    return 0;
}
