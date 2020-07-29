#include<stdio.h>
#define min(x,y)(x < y? x:y)

char a[200],b[200];
int as,bs;

int main(){
    while(scanf(" %d %s %d %s",&as,a,&bs,b) == 4){
        int dp[as+1][bs+1];
        for(int i = 0; i <= as;++i) dp[i][0] = i;
        for(int i = 0; i <= bs;++i) dp[0][i] = i;
        for(int i = 1;i <= as;++i){
            for(int j = 1; j <= bs;++j){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
                dp[i][j] = min(dp[i-1][j-1] + (a[i-1] != b[j-1]),dp[i][j]);
            }
        }
        printf("%d\n",dp[as][bs]);
    }
    return 0;
}
