#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[51][51];

int main(){
    int n,m,a,b;
    scanf(" %d %d",&n,&m);
    for(int i = 0; i < n;++i)
        for(int j = 0; j < m; ++j)
            scanf(" %d",&dp[i][j]);
    for(int j = 0; j < m;++j){
        for(int i = 0; i < n;++i){
            if(i > 0)
                dp[i][j] += dp[i-1][j];
            if(j > 0)
                dp[i][j] += dp[i][j-1];
            if(i > 0 && j > 0)
                dp[i][j] -= dp[i-1][j-1];
        }
    }
    scanf(" %d %d",&a,&b);
    int ans = 1000000000;
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j){
            if(i+a-1 < n && j+b-1 < m){
                int see = dp[i+a-1][j+b-1];
                if(i > 0)
                    see -= dp[i-1][j+b-1];
                if(j > 0)
                    see -= dp[i+a-1][j-1];
                if(i > 0 && j > 0)
                    see += dp[i-1][j-1];
                ans = min(ans,see);
            }
            if(i+b-1 < n && j+a-1 < m){
                int see = dp[i+b-1][j+a-1];
                if(i > 0)
                    see -= dp[i-1][j+a-1];
                if(j > 0)
                    see -= dp[i+b-1][j-1];
                if(i > 0 && j > 0)
                    see += dp[i-1][j-1];
                ans = min(ans,see);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
