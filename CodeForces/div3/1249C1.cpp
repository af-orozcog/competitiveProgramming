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

int main(){
	int q;
	scanf(" %d",&q);
	vector<ll> check;
	check.push_back(1);
	check.push_back(3);
	ll com = 10000;
	ll c = 3;
	while(c <= com){
		c*=3;
		check.push_back(c);
	}
	set<ll> nums;
	nums.insert(0);
	for(int i = 0; i < check.size();++i){
		vector<ll> add;
		for(auto &va:nums){
			add.push_back(va+check[i]);

		}
		for(auto &va:add){
			nums.insert(va);
		}
	}
	//cout << "here" << endl;
	while(q--){
		ll n;
		cin >> n;
		auto it = nums.lower_bound(n);
		cout << (*it) << endl;
	}
	return 0;
}