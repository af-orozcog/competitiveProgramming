#include<stdio.h>
#include<string.h>
#define ll long long

ll dp[1000][1000];
char let[1002];

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        scanf(" %s",let);
        int n = strlen(let);
        for(int i = 0; i < n;++i){
            dp[i][i] = 1;
        }
        for(int i = 1; i <= n-1;++i){
            for(int j = 0; j < n;++j){
                if(j+i ==n) break;
                dp[j][j+i] = dp[j+1][j+i] + dp[j][j+i-1];
                if(let[j] == let[j+i])
                    ++dp[j][j+i];
                else
                    dp[j][j+i] -= dp[j+1][j+i-1];
                //printf("%lld %d %d\n",dp[j][j+i],j,j+i);
            }
        }
        printf("%lld\n",dp[0][n-1]);
    }
    return 0;
}
