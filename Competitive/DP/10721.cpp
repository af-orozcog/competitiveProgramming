#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int n,k,m;
    while(scanf(" %d %d %d",&n,&k,&m) == 3){
        ll dp[2][n+1];
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= m;++i) dp[0][i] = 1;
        for(int i = 1; i < k;++i){
            for(int j = 1; j <= n;++j){
                for(int z = 1; z <= m;++z){
                    if(j - z > -1)
                        dp[1][j] += dp[0][j-z];
                }
            }
            memcpy(dp[0],dp[1],sizeof(dp[1]));
            memset(dp[1],0,sizeof(dp[1]));
        }
        printf("%lld\n",dp[0][n]);
    }
    return 0;
}
