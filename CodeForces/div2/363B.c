#include<stdio.h>

int main(){
	int n,k;
	scanf(" %d %d",&n,&k);
	int dp[n];
	scanf(" %d",&dp[0]);
	for(int i = 1;i < n;++i){
		int val;
		scanf(" %d",&val);
		dp[i] = dp[i-1] + val;
	}
	int ans;
	int dif = 1000000000;
	for(int i = 0; i < n-k+1;++i){
		int val;
		if(i == 0){
			val = dp[k-1];
		}
		else{
			val = dp[i+k-1]- dp[i-1];
		}
		if(val < dif){
			ans = i;
			dif = val;
		}
	}
	printf("%d\n",ans+1);
	return 0;
}