/**
* I only hope everything will be back to normal
*/
#include<bits/stdc++.h>
#define ll unsigned long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

int main(){
	ll n,k;
	cin >> n >> k;
	vector<ll> nums(n);
	vector<unordered_map<ll,ll>> inverse(11);
	ll powers[11];
	powers[0] =1 ;
	for(int i = 1; i <11;++i)
		powers[i] = powers[i-1]*10 % k;
	for(int i = 0; i < n;++i){
		ll va;cin >> va;
		nums[i] = va;
		ll dig = to_string(va).size();
		if(inverse[dig].count(va%k))
			++inverse[dig][va%k];
		else
			inverse[dig][va%k] = 1;
	}
	ll ans = 0;
	for(auto &va:nums){
		for(int i = 1; i < 11;++i){
			ll look = (va* powers[i]) %k;
			look = (k - look)%k;
			//cout << dig << " " << look << endl;
			if(inverse[i].count(look))
				ans+= inverse[i][look];
		}
		ll dig = to_string(va).size();
		if((va+(va*powers[dig]))%k == 0)
			--ans;
	}
	cout << ans << endl;
	return 0;
}