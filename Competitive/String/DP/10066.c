#include<stdio.h>
#define max(x,y)(x > y? x:y)
int as,bs,a[102],b[102];
int dp[102][102];


int main(){
    int cas = 1;
    while(scanf(" %d %d",&as,&bs) && as && bs){
        for(int i = 0; i < as;++i) dp[i][0] = scanf(" %d",&a[i])-1;
        for(int i = 0; i < bs;++i) dp[0][i] = scanf(" %d",&b[i])-1;
        dp[as][0] = dp[0][bs] = 0;
        for(int i = 1; i <= as;++i){
            for(int j = 1; j <= bs;++j){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = max(dp[i][j],dp[i-1][j-1] + (a[i-1] == b[j-1]));
            }
        }
        printf("Twin Towers #%d\n",cas++);
        printf("Number of Tiles : %d\n\n",dp[as][bs]);
    }
    return 0;
}
