#include<iostream>
#include<map>
#define ll long long
#define min(x,y)(x < y?x:y)

using namespace std;

map<pair<int,int>,ll> dp;

int siz;
int tar;
int costs[30];

ll solve(int i, int p,ll s){
	if(p >= tar)
		return s;
	if(i == siz)
		return 1000000000000;
	if(dp[make_pair(i,p)] != 0){
		cout << dp[make_pair(i,p)] << endl;
		return dp[make_pair(i,p)];
	}
	ll ans = 1000000000000;
	int neP = p | (1<<i);
	//cout << neP << endl;
	ans = min(ans,solve(i+1,neP,s +costs[i]));
	ans = min(ans,solve(i+1,p,s));
	return dp[make_pair(i,p)] = ans;
}

int main(){
	scanf(" %d %d",&siz,&tar);
	for(int i = 0; i < siz;++i){
		scanf(" %d", &costs[i]);
	}
	cout << solve(0,0,0) << endl;
	return 0;
}