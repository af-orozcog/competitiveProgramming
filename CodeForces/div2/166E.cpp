#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll M = 1000000007;

int main(){
    int n;
    scanf(" %d",&n);
    ll dp[2][4];
    memset(dp,0,sizeof(dp));
    dp[0][3] = 1;
    for(int i = 1; i <= n;++i){
        for(int j = 0; j < 4;++j){
            dp[1][j] += dp[0][(j+1)%4];
            if(dp[1][j] > M)
                dp[1][j] -= M;
            dp[1][j] += dp[0][(j+2)%4];
            if(dp[1][j] > M)
                dp[1][j] -= M;
            dp[1][j] += dp[0][(j+3)%4];
            if(dp[1][j] > M)
                dp[1][j] -= M;
        }
        memcpy(dp[0],dp[1],sizeof(dp[1]));
        memset(dp[1],0,sizeof(dp[1]));
    }
    printf("%lld\n",dp[0][3]);
}
