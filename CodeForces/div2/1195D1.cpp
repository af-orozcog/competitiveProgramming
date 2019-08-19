/**
* about to lose ranking
*/
#include<iostream>
#include<map>
#define ll unsigned long long

using namespace std;

ll M = 998244353;
ll dp[2][100000];

ll nums[100000];
int N;

void fill(){
	map<ll,pair<ll,ll>> va;
	for(int i = 0; i < N;++i){
		ll mul = 1;
		ll ans = 0;
		ll check = nums[i];
		if(va.count(check)){
			//cout << "here?" << endl;
			dp[1][i] = va[check].second;
			dp[0][i] = va[check].first;
			continue; 
		}
		while(check){
			ans += mul*(check%10);
			ans = ans %M;
			check /= 10;
			mul *= 100;
			mul = mul % M;
		}
		dp[1][i] = ans;
		//cout << " 1ans es: " <<ans <<endl;
		check = nums[i];
		va[check].second = ans;
		mul = 10;
		ans = 0;
		while(check){
			ans += mul*(check%10);
			ans = ans %M;
			check /= 10;
			mul *= 100;
			mul = mul % M;
		}
		//cout << " 2ans es " << ans << endl;
		dp[0][i] = ans;
		check = nums[i];
		va[check].first = ans;
	}
}

int main(){
	cin >> N;
	for(int i = 0; i < N;++i){
		cin >> nums[i];
	}
	fill();
	ll ans = 0;
	for(int i = 0; i < N;++i){
		ans += dp[0][i] * N;
		ans = ans % M;
		ans += dp[1][i] * N;
		ans = ans % M;
	}
	cout << ans << endl;
	return 0;
}