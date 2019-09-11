/**
* I do this because of Valentina, she motivates me :)
*/
#include<iostream>
#include<cstring>
#define max(x,y)(x > y?x:y)
#define ll long long

using namespace std;

int N,M,K;
ll nums[5001];
ll dp[5001][5001];
ll prefix[5001];

ll solve(int k,int p){
	if(k == K)
		return 0;
	if(p >= (N-M)+1)
		return -100000000000;
	if(dp[k][p] != -1)
		return dp[k][p];
	ll add;
	if(p == 0)
		add = prefix[(p+M)-1];
	else
		add = prefix[(p+M)-1]-prefix[p-1];
	return dp[k][p] = max(solve(k+1,p+M)+add,solve(k,p+1));
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf(" %d %d %d",&N,&M,&K);
	for(int i = 0; i < N;++i) cin >> nums[i];
	for(int i = 0; i < N;++i){
		if(i == 0)
			prefix[i] = nums[i];
		else
			prefix[i] = prefix[i-1] + nums[i];
	}
	cout << solve(0,0) << endl;
	return 0;
}