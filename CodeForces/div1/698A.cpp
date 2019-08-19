/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cstring>
#define min(x,y)(x < y?x :y)

using namespace std;

int dp[3][100];
int N;
short nums[100];

int solve(int l, int t){
	if(t == N)
		return 0;
	if(dp[l][t] != -1)
		return dp[l][t];
	if(l == 0){
		if(nums[t] == 3)
			return dp[l][t] = min(solve(1,t+1),solve(2,t+1));
		if(nums[t] == 1)
			return dp[l][t] = min(solve(1,t+1),1 + solve(0,t + 1));
		if(nums[t] == 2)
			return dp[l][t] = min(solve(2,t+1),1 + solve(0,t+1));
		return dp[l][t] = (1 + solve(0,t+1));
	}
	if(l == 1){
		if(nums[t] == 2 || nums[t] == 3)
			return dp[l][t] = min(solve(2,t+1),1 + solve(0,t+1));
		return dp[l][t] = 1 + solve(0,t+1);
	}
	else{
		if(nums[t] == 1 || nums[t] == 3)
			return dp[l][t] = min(solve(1,t+1), 1 + solve(0,t+1));
		return dp[l][t] = 1 + solve(0,t+1);
	}
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf(" %d",&N);
	for(int i = 0;i < N;++i){
		cin >> nums[i];
	}
	cout << solve(0,0) << endl;
}