#include<bits/stdc++.h>
using namespace std;

int dp[2006][2006];

int main(){
    int n,h,l,r;
    scanf(" %d %d %d %d",&n,&h,&l,&r);
    int when[n];
    for(int i = 1; i <= n;++i) scanf(" %d",&when[i]);
    for(int i = 0; i < 2006;++i){
        for(int j = 0; j < 2006;++j)
            dp[i][j] = -10000000;
    }
    dp[0][0] = 0;
    int ans = 0;
    for(int i = 1; i <= n;++i){
        for(int j = 0; j < h;++j){
            dp[i][j] = max(dp[i-1][(j-when[i]+h)%h],
                            dp[i-1][(j-when[i]+1+h)%h]) + (j >= l && j <=r);
            ans = max(dp[i][j],ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}
