#include<iostream>
#include<cstring>
#include<map>
#define ll long long
#define min(x,y)(x < y? x:y)
#include<climits>

using namespace std;

map<pair<int,int>,ll> dp;
int N;
int K;
ll ar[300000];

ll solve(int s, int k){
	if(k == K - 1){
		return ar[N-1] - ar[s];
	}
	if(dp.count(make_pair(s,k)))
		return dp[make_pair(s,k)];
	ll ans = LLONG_MAX;
	for(int i = s+1; i < N;++i){
		ll add = solve(i,k+1);
		if(add == LLONG_MAX)
			break;
		ans = min(ans, ar[i-1] - ar[s] + add);
	}
	return dp[make_pair(s,k)] = ans;
}

int main(){
	dp.clear();
	cin >> N >> K;
	for(int i = 0; i < N;++i){
		cin >> ar[i];
	}
	cout << solve(0,0) << endl;
}