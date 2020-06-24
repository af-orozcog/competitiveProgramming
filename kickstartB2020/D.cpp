#include<bits/stdc++.h>
#define ld long double
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int w,h,l,u,r,d;
        scanf(" %d %d %d %d %d %d",&w,&h,&l,&u,&r,&d);
        --l,--u,--r,--d;
        ld dp[h][w];
        for(int i = 0; i < h;++i)
            for(int j = 0; j < w;++j)
                dp[i][j] = 0.0;
        dp[h-1][w-1] = 1.0;
        for(int i = h-1;i > -1;--i){
            for(int j = w-1; j > -1;--j){
                if(i == h-1 && j == w-1)continue;
                if(i >= u && i <= d && j >= l && j <= r) continue;
                if(i == h-1) dp[i][j] = dp[i][j+1];
                else if(j == w-1) dp[i][j] = dp[i+1][j];
                else{
                    dp[i][j] += dp[i+1][j]*(ld)0.5;
                    dp[i][j] += dp[i][j+1]*(ld)0.5;
                }
            }
        }
        printf("Case #%d: %.06Lf\n",cas++,dp[0][0]);
    }
    return 0;
}
