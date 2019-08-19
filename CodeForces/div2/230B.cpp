/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cmath>
#include<bitset>
#include<vector>
#define ll long long

using namespace std;
bitset<1000001> pos;
vector<ll> nums;

void sieve(){
	pos.set();
	for(ll i = 2; i <= 1000000; ++i){
		if(pos[i]){
			ll m = 2;
			while(i * m <= 1000000){
				pos.set(i*m,0);
				++m;
			}
			nums.push_back(i*i);
		}
	}
}

int main(){
	sieve();
	int cas;
	cin >> cas;
	while(cas--){
		ll val;
		cin >> val;
		vector<ll>::iterator low = lower_bound(nums.begin(),nums.end(),val);
		int ind = low - nums.begin();		
		if(nums[ind] == val)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}