#include<stdio.h>
#define max(x,y)(x > y? x:y)

int a[900],b[900];
int dp[901][901];
int as,bs;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d %d %d",&n,&as,&bs);
        for(int i = 0; i <= as;++i) scanf(" %d",&a[i]);
        for(int i = 0; i <= bs;++i) scanf(" %d",&b[i]);
        for(int i = 0; i <= as;++i) dp[i][0] = 0;
        for(int i = 0; i <= bs;++i) dp[0][i] = 0;
        for(int i = 1; i <= as;++i){
            for(int j = 1; j <= bs;++j){
                if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("Case %d: %d\n",cas++,dp[as][bs]+1);
    }
}
