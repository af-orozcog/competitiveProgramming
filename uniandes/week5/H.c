#include<stdio.h>
#include<string.h>
#define min(x,y)(x < y? x:y)

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m,co1,co2;
        scanf(" %d %d %d %d",&n,&m,&co1,&co2);
        int dp[m+1];
        int ans = 0;
        char row[m+1];
        for(int i = 0; i < n;++i){
            scanf(" %s",row);
            memset(dp,0,sizeof(dp));
            for(int j = m-1; j > -1;--j){
                if(row[j] == '*') dp[j] = dp[j+1];
                else{
                    dp[j] = co1 + dp[j+1];
                    if(j < m-1 && row[j+1] != '*')
                        dp[j] = min(dp[j],co2+dp[j+2]);
                }
            }
            ans += dp[0];
        }
        printf("%d\n",ans);
    }
    return 0;
}
