#include<iostream>
#include<cstring>
#define min(x,y)(x < y? x:y)
#define ll long long

using namespace std;

ll M = 998244353;

ll dp[201][100000];
int N;
int ar[100000];

int mn(int p,int m){
	int co;
	if(p - 1 < 0)
		co = ar[p+1];
	if(p + 1 >= N){
		co = ar[p-1];
		if(co == 0)
			co = m;
	}
	else
		co = min(ar[p-1],ar[p+1]);
	return co;
}


ll solve(int m, int p){
	if(p == N)
		return 1;
	if(dp[m][p] != -1)
		return dp[m][p];
	ll ans = 0;
	int co = mn(p,m);
	if(co > m)
		return 0;
	bool le = true;
	if(m > ar[p])
		le = false; 
	if(ar[p] != 0){
		if(ar[p] < co)
			return 0;
		else{
			ans += solve((le?200:ar[p]),p+1) %M;
		}
	}
	if(ar[p] == 0){
		for(int i = co;i <= m;++i){
			if(i == 0)
				continue;
			ans += solve(i,p+1) % M;
		}
	}
	return dp[m][p] = ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin >> N;
	for(int i = 0; i < N;++i){
		cin >> ar[i];
		if(ar[i] == -1)
			ar[i] = 0;
	}
	cout << solve(200,0) << endl;
}