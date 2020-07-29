#include<stdio.h>
#include<string.h>
#define max(x,y)(x > y?x:y)

int dp[1002][1002];
char a[1003],b[1003];

int main(){
    while(gets(a)){
        gets(b);
        int as = strlen(a),bs = strlen(b);
        for(int i = 0; i <= as;++i) dp[i][0] = 0;
        for(int i = 0; i <= bs;++i) dp[0][i] = 0;
        for(int i = 1; i <= as;++i){
            for(int j = 1; j <= bs;++j){
                if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[as][bs]);
    }
    return 0;
}
