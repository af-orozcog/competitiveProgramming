#include<bits/stdc++.h>
using namespace std;

const int M = 1000000007;

int dp[10][1001][1001];

int m,n;

int main(){
    memset(dp,-1,sizeof(dp));
    scanf(" %d %d",&n,&m);
    int ans = 0;
    for(int i = 1;i < n+1;++i){
        for(int j = n; j >= i;--j){
            dp[0][i][j] = 1;
        }
    }

    printf("%d\n",ans);
    return 0;
}
