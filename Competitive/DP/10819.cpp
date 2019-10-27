#include<iostream>
#include<cstring>
#include<vector>
#define max(x,y)(x > y?x:y)
#define min(x,y)(x < y?x:y)

using namespace std;

int main(){
	int m,n;
	while(scanf(" %d %d",&m,&n) == 2){
		int we[n];
		int val[n];
		for(int i = 0; i < n;++i) scanf(" %d %d",&we[i],&val[i]);
		int dp[2][400001];
		memset(dp,-1,sizeof(dp));
		dp[0][0] = dp[1][0] = 0;
		int ans = 0;
		for(int i = 0; i < n;++i){
			for(int j = 0; j <= min(400000-we[i],m+200-we[i]);++j){
				if(dp[0][j] != -1){
					dp[1][j+we[i]] = max(dp[1][j+we[i]],dp[0][j] + val[i]);
					if((j + we[i] <= m) || (j+we[i] > 2000 && m + 200 >= j+we[i]))
						ans = max(dp[1][j+we[i]],ans); 
				}
			}
			//for(int j = 0; j < 2000;++j)
			//	cout << j <<" " <<dp[1][j] << " ";
			//cout << endl; 
			memcpy(dp[0],dp[1],sizeof(dp[0]));
		}
		//printf("%d\n",dp[0][1500]);
		printf("%d\n",ans);
	}
	return 0;
}