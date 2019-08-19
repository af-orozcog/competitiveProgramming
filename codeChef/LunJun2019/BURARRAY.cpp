/**
* I'm sorry I was an idiot
*/
#include<map>
#include<iostream>
#define ll long long

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		ll N;
		int que;
		cin >> N;
		cin >> que;
		map<ll,ll> changed;
		ll sum = 0;
		while(que--){
			int type;
			ll val1,val2;
			cin >> type;
			if(type == 1){
				cin >> val1;
				changed[val1 + sum] = 0;
			}
			else{
				cin >> val1 >> val2;
				ll ans = 0;
				val1 += sum;
				val2 += sum;
				for(ll i = val2; i >= val1;--i){
					if(changed.count(i) == 0){
						ans = i;
						break;
					}
				}
				cout << ans << endl;
				sum += ans;
				sum = sum % N;
				cout << "sum is :"  << sum << endl; 
			}
		}
	}
	return 0;
}