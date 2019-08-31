#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int dp[20001];
	int t;
	scanf(" %d",&t);
	while(t--){
		int val,siz;
		scanf(" %d %d",&val,&siz);
		for(int j = 0; j < 20002;++j)
			dp[j] = 1000000000;
		dp[0] = 0;
		int coins[siz];
		for(int i = 0; i < siz;++i)
			scanf(" %d",&coins[i]);
		for(int i = 0; i < siz;++i){
			for(int j = 20000-coins[i]; j >= 0;--j){
				if(dp[j] != 1000000000)
					dp[j+coins[i]] = min(dp[j+coins[i]],dp[j]+1);
			}
		}
		for(int i = val; i <= 20002;++i){
			if(dp[i] != 1000000000){
				printf("%d %d\n",i,dp[i]);
				break;
			}
		}
	}
}