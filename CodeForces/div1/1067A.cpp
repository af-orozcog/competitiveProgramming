//ALL I DO IS WRONG
#include<iostream>
#include<string.h>
#define ll long long
#define max(x,y)(x > y? x:y)
#define M 998244353

using namespace std;


ll dp[2][201][100001];
int N;
int ar[100000];

ll solve(int f,int l,int p){
	if(p == N && f == 0)
		return 1;
	if(p == N)
		return 0;
	if(ar[p] != -1){
		if(f && ar[p] < l)
			return 0;
		ll ans = 0;
		if(ar[p] == l)
		    ans += solve(0,ar[p],p+1);
		ans += solve(1,ar[p],p+1);
		ans = ans % M;
		return dp[f][l][p] = ans;
	}
	if(dp[f][l][p] != -1)
		return dp[f][l][p];
	ll ans = 0;
	if(f == 0){
		for(int i = 1; i <= 200;++i){
			if(l < i)
				ans += solve(0,i,p+1);
			else
				ans += solve(1,i,p+1);
			ans = ans%M;
		}
	}
	else{
		for(int i = l;i <= 200;++i){
			if(l == i)
				ans += solve(0,i,p+1);
			else
				ans += solve(1,i,p+1);
			ans = ans%M;
		}
	}
	return dp[f][l][p] = ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf(" %d",&N);
	for(int i = 0; i < N;++i) scanf(" %d",&ar[i]);
	ll ans = 0;
	if(ar[0] == -1){
		for(int i = 1; i <= 200; ++i){
			ans += solve(1,i,1);
			ans = ans%M;
		}
	}
	else
		ans = solve(1,ar[0],1);
	cout << ans << endl;
}