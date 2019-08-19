#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#define ll unsigned long long
#include<map>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	map<ll,ll> tra;
	ll primes[]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
	for(int i = 0; i < n;++i){
		ll id = 1;
		for(int j = 0; j < 10;++j){
			char c;
			scanf(" %c",&c);
			id *= primes[c - 'a'];
		}
		//cout << id<<endl;
		if(tra.count(id)){
			++tra[id];
		}
		else
			tra[id] = 1;
	}
	ll ans = 0;
	for(const auto &pa: tra)
		ans += (((pa.second)*(pa.second-1))>>1);
	cout << ans << endl;
}