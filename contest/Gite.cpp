#include<iostream>
#include<cstring>
#define ll long long
#define M 1000000007

using namespace std;
ll mod1;
ll mod2;
ll mod0;
int N;

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
	ll dp[2][3] = {{mod0,mod1,mod2},{0,0,0}};
	//cout << dp[0][0] << " " << dp[0][1] << " " << dp[0][2] << endl;
	for(int i = 1; i < N;++i){
		dp[1][0] = ((dp[0][2] * mod1)%M+(dp[0][1]*mod2)%M+(dp[0][0]*mod0)%M)%M;
		dp[1][1] = ((dp[0][0]* mod1)%M + (dp[0][1]*mod0)%M + (dp[0][2]*mod2)%M)%M;
		dp[1][2] = ((dp[0][1] * mod1)%M + (dp[0][2]*mod0)%M + (dp[0][0]*mod2)%M)%M;
		//cout << dp[0][0] << endl;
		for(int i = 0; i < 3;++i)
			dp[0][i] = dp[1][i];
		memset(dp[1],0,sizeof(dp[1]));
		//cout << dp[0][0] << " " << dp[0][1] << " " << dp[0][2] << endl;
	}
	cout << dp[0][0] << endl;
	return 0;
}