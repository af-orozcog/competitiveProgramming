#include<iostream>
#include<cstring>
#define ll long long

using namespace std;

int coins[] = {50,25,10,5,1};

ll dp[5][7490];

ll solve(int p,int s){
	if(s == 0)
		return 1;
	if(p == 5 || s <= 0)
		return 0;
	if(dp[p][s] != -1)
		return dp[p][s];
	return dp[p][s] = solve(p,s-coins[p]) + solve(p+1,s);
}

int main(){
	memset(dp,-1,sizeof(dp));
	int N;
	while(scanf(" %d",&N) == 1)
		cout << solve(0,N)<<"\n";
	return 0;
}