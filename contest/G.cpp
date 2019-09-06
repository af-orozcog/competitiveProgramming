#include<iostream>
#include<cstring>
#define ll long long
#define M 1000000007

using namespace std;

ll dp[200000][3];
ll mod1;
ll mod2;
ll mod0;
int N;

ll solve(int p, int r){
	if(p == N){
		if(r == 0)
			return 1;
		return 0;
	}
	if(dp[p][r] != -1)
		return dp[p][r];

	ll ans = (mod0*solve(p+1,r)) % M;
	ans += (mod1)*solve(p+1,(r+1)%3);
	ans = ans % M;
	ans += (mod2)*solve(p+1,(r+2)%3);
	ans = ans % M;
	return dp[p][r] = ans;
}

int main(){
	int l,r;
	scanf(" %d %d %d",&N,&l,&r);
	int T = ((r - l) + 1)/3;
	int t = ((r-l)+1)%3;
	ll ar[3] = {T,T,T};
	ll R = l % 3;
	if(t == 1){
		++ar[R];
	} 
	else if(t == 2){
		++ar[(R+1)%3];
		++ar[R];
	}
	mod0 = ar[0];
	mod1 = ar[1];
	mod2 = ar[2];
//	cout << mod0 << " " << mod1 << " " << mod2 << endl; 
	memset(dp,-1,sizeof(dp));
	ll ans = mod0*solve(1,0);
	ans += mod1*solve(1,1);
	ans = ans % M;
	ans += mod2*solve(1,2);
	ans = ans % M;
	cout << ans << endl;
}
