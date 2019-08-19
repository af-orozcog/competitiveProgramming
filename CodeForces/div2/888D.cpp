#include<iostream>
#include<cstring>
#define ll long long
#define max(x,y)(x > y? x:y)

using namespace std;

ll dp[1000][1000];
int n,k;

ll solve(int p,int m){
	if(m > k)
		return 0;
	if(p == n){
		if(m == k)
			return 1;
		return 0;
	}
	if(dp[p][m] != -1)
		return dp[p][m];
	ll ans = solve(p+1,m+1);
	ans += max(n-(p+1),1)*solve(p+1,m);
	return dp[p][m] = ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf(" %d %d",&n,&k);
	k = n - k;
	cout << solve(0,0) << endl;
	return 0;
}