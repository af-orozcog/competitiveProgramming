#include<iostream>
#include<cstring>
#define max(x,y)(x > y? x:y)

using namespace std;

int N,M;
int dp[11][300001];
int ene[300001];

int solve(int m,int p){
	if(p == N)
		return 0;
	if(dp[m][p] != -1)
		return dp[m][p];
	int ans = 0;
	if(m == M)
		ans = max(ene[p]+solve(1,p+1),solve(m,p+1));
	else
		ans = solve(m+1,p+1);
	return dp[m][p] = ans; 
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf(" %d %d",&N,&M);
	for(int i = 0; i < N;++i) scanf(" %d",&ene[i]);
	int ans = solve(0,0);
	printf("%d\n",ans);
	return 0;
}