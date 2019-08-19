#include<iostream>
#include<cstring>
#define ll long long
#define M 998244353

using namespace std;
ll dp[2000][2000];

int n,m,k;

ll solve(int p,int t){
	if(p == n){
		if(t == k)
			return 1;
		else
			return 0;
	}
	if(t > k)
		return 0;
	if(p == 0){
		return dp[p][t] = (solve(p+1,t) %M);
	}
	if(dp[p][t] != -1)
		return dp[p][t];
	ll ans = solve(p+1,t) % M;
	ans += solve(p+1,t+1)*(m-1);
	ans = ans % M;
	return dp[p][t] = ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf(" %d %d %d",&n,&m,&k);
	cout << ((solve(0,0)*m)%M) << endl;
	return 0;
}