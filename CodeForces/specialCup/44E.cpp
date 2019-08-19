#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

short dp[203][203];
string ans[203][203];

string read;

int k,a,b;

bool solve(int l,int p){
	if(p == read.size()){
		if(l == k)
			return 1;
		else
			return 0;
	}
	if(dp[l][p] != -1)
		return dp[l][p];
	for(int i = p + a; i <= (p + b) && i <= read.size();++i){
		if(solve(l+1,i)){
			ans[l][p] = read.substr(p,i-p);
			return dp[l][p] = 1;
		}
	}
	return dp[l][p] = 0;
}

int main(){
	scanf(" %d %d %d",&k,&a,&b);
	cin >> read;
	memset(dp,-1,sizeof(dp));
	if(solve(0,0)){
		int co = 0;
		for(int i = 0; i < k;++i){
			cout << ans[i][co] << endl;
			co += ans[i][co].size();
		}
	}
	else
		puts("No solution");
	return 0;
}