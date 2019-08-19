/**
* about to lose ranking
*/
#include<iostream>
#include<cstring>
#define ll long long
#define max(x,y)(x > y? x:y)

using namespace std;


ll dp[2][100000];
int N;
ll ply[2][100000];

ll solve(int r,int t){
	if(t == N)
		return 0;
	if(dp[r][t] != -1)
		return dp[r][t];
	return dp[r][t] = max(ply[r][t] + solve((r == 1? 0:1),t+1),solve(r,t+1));
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin >> N;
	for(int i = 0; i < N;++i){
		cin >> ply[0][i];
	}
	for(int i = 0; i < N;++i){
		cin >> ply[1][i];
	}
	ll ans = max(solve(0,0),solve(1,0));
	cout << ans << endl;
}