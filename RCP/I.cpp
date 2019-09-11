#include<iostream>
#include<cstring>
#define max(x,y)(x > y? x:y)

using namespace std;

int N,M;
int dp[300000];
int ene[300000];

int solve(int p){
	if(p >= N)
		return 0;
	if(dp[p] != -1)
		return dp[p];
	int ans = ene[p];
	int val = 0;
	for(int i = p + M; i < N;++i){
		val = max(val,solve(i));
	}
	return dp[p] = (val +ans); 
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf(" %d %d",&N,&M);
	for(int i = 0; i < N;++i) scanf(" %d",&ene[i]);
	int ans = 0;
	for(int i = M+1; i < N;++i){
		ans = max(ans,solve(i));
	}
	printf("%d\n",ans);
	return 0;
}