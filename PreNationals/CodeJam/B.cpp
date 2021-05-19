#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll INF = 10000000000000LL;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        ll x,y; string see;
        cin >> x >> y >> see;
        int n = see.size();
        ll dp[2][n];
        memset(dp,0,sizeof(dp));
        dp[1][0] = dp[0][0] = INF;
        if(see[0] == 'C') dp[0][0] = 0;
        else if(see[0] == 'J') dp[1][0] = 0;
        else dp[1][0] = dp[0][0] = 0;
        for(int i = 1; i < n;++i){
            dp[0][i] = dp[1][i] = INF;
            if(see[i] == 'C')
                dp[0][i] = min(dp[0][i-1],dp[1][i-1]+y);
            if(see[i] == 'J')
                dp[1][i] = min(dp[1][i-1],dp[0][i-1]+x);
            if(see[i] == '?'){
                dp[0][i] = min(dp[0][i-1],dp[1][i-1]+y);
                dp[1][i] = min(dp[1][i-1],dp[0][i-1]+x);
            }
        }
        printf("Case #%d: %lld\n",cas++,min(dp[0][n-1],dp[1][n-1]));
    }
    return 0;
}
