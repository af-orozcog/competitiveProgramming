#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[501][501];

int modd(int x, int mo){
    while(x >= mo) x -= mo;
    return x;
}

int main(){
    int n,m,b,mod;
    scanf(" %d %d %d %d",&n,&m,&b,&mod);
    int errors[n+1];
    ll ans = 0;
    dp[0][0] = 1;
    for(int i = 1; i <= n;++i){scanf(" %d",&errors[i]);}
    for(int i = 1; i <= n;++i){
        for(int j = 1; j <= m;++j){
            for(int k = 0; k <= b;++k){
                if(k - errors[i] > -1)
                    dp[j][k] += dp[j-1][k-errors[i]];
                dp[j][k] = modd(dp[j][k],mod);
                if(j == m && i == n)
                    ans += dp[j][k];
                //printf("%d %d %d %lld\n",i,j,k,dp[i][j][k]);
                ans = modd(ans,mod);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
