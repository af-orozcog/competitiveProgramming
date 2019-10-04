#include<iostream>
#include<cstring>
#define max(x,y)(x > y? x:y)

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int N;
		scanf(" %d",&N);
		int price[N];
		int weight[N];
		for(int i = 0; i < N;++i)
			scanf(" %d %d",&price[i],&weight[i]);
		int P;
		scanf(" %d",&P);
		int ans = 0;
		while(P--){
			int we;scanf(" %d",&we);
			int dp[2][we+1];
			memset(dp,-1,sizeof(dp));
			for(int i = 0; i < N;++i){
				dp[0][0] = 0;
				int j = 0;
				while(j + weight[i] <= we){
					if(dp[0][j] != -1)
						dp[1][j+weight[i]] = max(dp[1][j+weight[i]],dp[0][j]+price[i]);
					++j;
				}
				memcpy(dp[0],dp[1],sizeof(dp[0]));
				//for(int j = 0; j <= we;++j) printf("%d ",dp[0][j]);
				//puts("");
			}
			int add = 0;
			for(int i = 0; i <= we;++i)
				add = max(add,dp[0][i]);
			ans += add;
		}
		printf("%d\n",ans);
	}
	return 0;
}