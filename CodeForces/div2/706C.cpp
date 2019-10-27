#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define min(x,y)(x < y?x:y)


using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	ll costs[n];
	for(int i = 0; i < n;++i) cin >> costs[i];
	vector<string> normal(n);
	vector<string> reve(n);
	for(int i = 0; i < n;++i){
		string re; cin >> re;
		string co = re;
		reverse(co.begin(),co.end());
		normal[i] = re;
		reve[i] = co;
	}
	ll dp[2][2];
	dp[0][0] = 0;
	dp[0][1] = costs[n-1];
	dp[1][0] = 100000000000000;
	dp[1][1] = 100000000000000;
	for(int i = n-2;i > -1;--i){
		if(normal[i].compare(normal[i+1]) <= 0)
			dp[1][0] = min(dp[1][0],dp[0][0]);
		if(normal[i].compare(reve[i+1]) <= 0)
			dp[1][0] = min(dp[1][0],dp[0][1]);
		if(reve[i].compare(normal[i+1]) <= 0)
			dp[1][1] = min(dp[1][1],dp[0][0]+costs[i]);
		if(reve[i].compare(reve[i+1]) <= 0)
			dp[1][1] = min(dp[1][1],dp[0][1]+costs[i]);
		memcpy(dp[0],dp[1],sizeof(dp[0]));
		dp[1][0] = 100000000000000;
		dp[1][1] = 100000000000000;
	}
	ll ans = min(dp[0][0],dp[0][1]);
	if(ans >= 100000000000000)
		puts("-1");
	else
		cout << ans << endl;
	return 0;
}