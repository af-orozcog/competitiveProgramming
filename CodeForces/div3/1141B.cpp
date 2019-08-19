#include<iostream>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	int nums[n];
	for(int i = 0; i < n;++i)
		scanf(" %d",&nums[i]);
	int dp[n];
	int ans = 0;
	for(int i = 0; i < n;++i){
		int cum = 0;
		int m = i;
		while(m < n && nums[m]){
			++cum;
			++m;
		}
		if(m == n){
			cum += dp[0];
		}
		dp[i] = cum;
		if(cum > ans)
			ans = cum;
		if(m > i)
			i = m - 1;
	}
	printf("%d\n",ans);
	return 0;
}