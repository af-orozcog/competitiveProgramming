#include<stdio.h>
#define max(x,y)( x > y? x:y)

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int r,c;
        scanf(" %d %d",&r,&c);
        int dp[r][c];
        for(int i = 0; i < r;++i){
            for(int j = 0; j < c;++j) scanf(" %d",&dp[i][j]);
        }
        for(int i = r-2;i > -1;--i){
            for(int j = 0; j < c;++j){
                int temp = dp[i][j];
                if(j > 0)
                    dp[i][j] = max(dp[i][j],temp + dp[i+1][j-1]);
                if(j < c-1)
                    dp[i][j] = max(dp[i][j], temp + dp[i+1][j+1]);
                dp[i][j] = max(dp[i][j],temp + dp[i+1][j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < c;++i) ans = max(ans,dp[0][i]);
        printf("%d\n",ans);
    }
    return 0;
}
