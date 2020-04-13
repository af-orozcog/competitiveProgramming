#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        int dp[n][m];
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m;++j) scanf(" %d",&dp[i][j]);
        }
        int ans = 0;
        for(int i = n-2;i > -1;--i){
            for(int j = 0; j < m;++j){
                int temp = dp[i][j];
                dp[i][j] = temp + dp[i+1][j];
                if(j > 0) dp[i][j] = max(dp[i][j], temp + dp[i+1][j-1]);
                if(j < m-1) dp[i][j] = max(dp[i][j],temp + dp[i+1][j+1]);
                ans = max(dp[i][j],ans);
            }
        }
        printf("%d\n",ans);
	}
	return 0;
}
