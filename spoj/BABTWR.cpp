#include<bits/stdc++.h>
using namespace std;

int dp[2501][2501];
int va[3][30];
int n;

int solve(int a,int b){
    if(dp[a][b] != -1) return dp[a][b];
    dp[a][b] = 0;
    for(int i = 0; i < n;++i){
        for(int j = 0; j < 3;++j){
            if(va[j][i] < a && va[(j+1)%3][i] < b)
                dp[a][b] = max(dp[a][b],va[(j+2)%3][i] + solve(va[j][i],va[(j+1)%3][i]));
            if(va[(j+1)%3][i] < a && va[j][i] < b)
                dp[a][b] = max(dp[a][b],va[(j+2)%3][i] + solve(va[(j+1)%3][i],va[j][i]));
        }
    }
    return dp[a][b];
}

int main(){
    while(scanf(" %d",&n) == 1 && n){
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < n;++i)
            scanf(" %d %d %d",&va[0][i],&va[1][i],&va[2][i]);
        int ans = 0;
        for(int i = 0; i < n;++i){
            for(int j = 0; j < 3;++j){
                ans = max(ans,va[(j+2)%3][i] + solve(va[j][i],va[(j+1)%3][i]));
                ans = max(ans,va[(j+2)%3][i] + solve(va[(j+1)%3][i],va[j][i]));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
