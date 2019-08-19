/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#define ll long long
#define min(x,y)(x <y?x:y)

using namespace std;

int main(){
	ll siz,k;
	cin >> siz >> k;
	int total = 0;
	vector<ll> save(k,0);
	for(ll i = 0; i < siz;++i){
		ll val;
		cin >> val;
		++save[val%k];
	}
	ll ans = 0;
	ans += (save[0] >> 1);
	if(k% 2 == 0){
		ans += (save[k>>1] >> 1);
		save[k>>1] = 0;
	}
	for(int i = 1; i <= (k>>1);++i){
		ll m = min(save[i],save[k-i]);
		ans += m;
		save[i]-=m;
		save[k-1]-=m;

	}
	cout << (ans<<1) << endl; 
}