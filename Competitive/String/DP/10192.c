#include<stdio.h>
#include<string.h>
#define max(x,y)(x > y? x:y)
int dp[102][102];
char a[103],b[103];
int main(){
    int cas = 1;
    while(gets(a)){
        if(strcmp(a, "#") == 0)break;
        gets(b);
        int as = strlen(a),bs = strlen(b);
        for(int i = 0; i <= as;++i) dp[0][i] = 0;
        for(int i = 0; i <= bs;++i) dp[i][0] = 0;
        for(int i = 1; i <= as;++i){
            for(int j = 1; j <= bs;++j){
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                if(a[i-1] == b[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",cas++,dp[as][bs]);
    }
    return 0;
}
