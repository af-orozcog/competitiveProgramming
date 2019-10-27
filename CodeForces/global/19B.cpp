/**
* I only hope everything will be back to normal
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

ll dp[2008];
int solve(int p,vector<pair<ll,ll>> &ar){
	if(dp[p] != -1)
		return dp[p];
	ll ans = 
}

int main(){
	int n;
	scanf(" %d",&t);
	vector<pair<ll,ll>> pos(n);
	memset(dp,-1,sizeof(dp));
	for(int i = 0; i < n;++i) cin >> pos[i].first >> pos[i].second;
	sort(pos.begin(),pos.end());
	cout << solve(0,pos) << endl;
	return 0;
}