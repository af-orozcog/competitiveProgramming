#include<stdio.h>
#include<stdlib.h>
#define max(x,y)(x > y? x:y)

int main(){
    int n;
    scanf(" %d",&n);
    int va1[n],va2[n];
    for(int i = 0; i < n;++i) scanf(" %d %d",&va1[i],&va2[i]);
    int dp[2][n];
    dp[0][0] = va1[0], dp[1][0] = va2[0];
    for(int i = 1; i < n;++i){
        dp[0][i] = max(dp[0][i-1]+abs(va2[i]-va2[i-1]),dp[1][i-1]+abs(va2[i]-va1[i-1]))+va1[i];
        dp[1][i] = max(dp[0][i-1]+abs(va1[i]-va2[i-1]),dp[1][i-1]+abs(va1[i]-va1[i-1]))+va2[i];
    }
    printf("%d\n",max(dp[0][n-1],dp[1][n-1]));
    return 0;
}
