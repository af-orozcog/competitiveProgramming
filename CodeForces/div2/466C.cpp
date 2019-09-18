/**
* I'll calm myself, sorry
*/
#include<iostream>
#include<cstring>
#define ll long long

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	ll nums[n];
	ll sum =0;
	for(int i = 0; i < n;++i){
		ll val;cin >> val;
		sum += val;
		nums[i] = val;
	}
	if(sum % 3 != 0){
		puts("0");return 0;
	}
	ll tar = sum /3;
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	sum = nums[0];
	if(sum == tar) dp[0] = 1;
	for(int i = 1; i < n;++i){
		sum += nums[i];
		if(sum == tar)
			++dp[i];
		dp[i] += dp[i-1];
	}
	ll ans = 0;
	sum = 0;
	for(int i = n-1;i >= 2;--i){
		sum += nums[i];
		if(sum == tar)
			ans += dp[i-2];
	}
	cout << ans << endl;
	return 0;
}