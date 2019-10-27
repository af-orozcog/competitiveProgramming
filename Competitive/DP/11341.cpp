#include<iostream>
#include<cstring>
#include<vector>
#define max(x,y)(x > y?x:y)
#define min(x,y)(x < y?x:y)

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int n,m;
		scanf(" %d %d",&n,&m);
		int vals[n][m+1];
		for(int i = 0; i < n;++i){
		  for(int j = 1; j <= m;++j)
		   		scanf(" %d",&vals[i][j]);
		}
		int dp[2][m+1];
		dp[0][0] = dp[1][0] = 0.0;
		for(int i = 1; i <= m;++i){
			dp[0][i] = (vals[0][i] < 5? 0: vals[0][i]);
			dp[1][i] = 0.0;
		}
		for(int i = 1;i < n;++i){
			for(int j = 1; j <= m;++j){
				if(vals[i][j] < 5)
					continue;
				for(int k = 1; k < m; ++k){
					if(k+j > m)
						break;
					if(dp[0][k] == 0.0)
						continue;
					dp[1][k+j] = max(dp[1][k+j],(dp[0][k]+vals[i][j]));
				}
			}
			memcpy(dp[0],dp[1],sizeof(dp[1]));
			memset(dp[1],0,sizeof(dp[1]));
			//cout << endl;
		}
		int ans = 0;
		for(int i = 0;i <= m; ++i) ans = max(ans,dp[0][i]);
		if(ans == 0)
			puts("Peter, you shouldn't have played billiard that much.");
		else
			printf("Maximal possible average mark - %.2f.\n",(double)ans/(double)n 1.0e-9);
	}
} 