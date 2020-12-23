#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int cap[n],wat[n];
    int capS = 0,watS = 0;
    for(int i = 0; i < n;++i){
        scanf(" %d %d",&cap[i],&wat[i]);
        capS += cap[i];
        watS += wat[i];
    }
    int dp[n+1][capS+1];
    for(int i = 0; i <= n;++i)
        for(int j = 0; j <= capS;++j)
            dp[i][j] = INT_MIN;
    dp[0][0] = 0;
    for(int i = 0; i < n;++i){
        for(int j = n; j > 0;--j){
            for(int k = capS; k >= 0;--k){
                if(k - cap[i] >= 0)
                    dp[j][k] = max(dp[j][k],dp[j-1][k-cap[i]]+wat[i]);
            }
        }
    }
    for(int i = 1; i <= n;++i){
        double temp = 0;
        for(int j = 0; j <= capS;++j){
            if(dp[i][j] > -1)
                temp = max(temp, min((double)j,(double)watS/2.0 + (double)dp[i][j]/2.0));
        }
        printf("%.9f ",temp);
    }
    puts("");
    return 0;
}
