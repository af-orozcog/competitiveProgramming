#include<iostream>
#include<cstring>

using namespace std;

int dp[10001][100];
int nums[10001];
int siz,K;

bool solve(int p,int r){
	//cout << p << " " << r<<endl;
	if(p == siz){
		//cout << "entra?" << p<< " "<<siz<<endl;
		//cout << "r es " << r << endl;
		if(r != 0)
			return false;
		return true;
	}
	if(dp[p][r] != -1){
		//cout << dp[p][r] << endl;
		return dp[p][r];
	}
	int re1 = (r - nums[p]) % K;
	if(re1 < 0)
		re1 += K;
	int re2 = (r + nums[p]) % K;
	int ans = solve(p+1,re1);
	//if(ans > 0)
	//	cout << "aqui" <<ans<< endl;
	ans += solve(p+1,re2);
	return dp[p][r] = ans;
}

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		memset(dp,-1,sizeof(dp));
		scanf(" %d %d",&siz,&K);
		for(int i = 0; i < siz;++i)
			scanf(" %d",&nums[i]);
		int ans = solve(0,0);
//		cout <<"here is what" <<ans << endl;
		if(ans)
			puts("Divisible");
		else
			puts("Not divisible");
	}
	return 0;
}