#include<bits/stdc++.h>
using namespace std;

int main(){
    int dp[10001];
    dp[0] = 0;
    for(int i = 1; i < 10001;++i){
        dp[i] = 1000000000;
        for(int j = 1; j*j <= i;++j)
            dp[i] = min(dp[i-j*j]+1,dp[i]);
    }
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;scanf(" %d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
