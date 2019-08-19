/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

bool com(const ll a, const ll b){
	return a > b;
}

int main(){
	int que;
	cin >> que;
	while(que--){
		int siz;
		cin >> siz;
		map<ll,ll> freq;
		for(int i = 0; i < siz;++i){
			ll val;
			cin >> val;
			if(freq.count(val) == 0)
				freq[val] = 1;
			else
				++freq[val];
		}
		vector<ll> nefre;
		for(auto const &pa: freq){
			nefre.push_back(pa.second);
		}
		sort(nefre.begin(),nefre.end(),com);
		ll last = nefre[0];
		ll ans = last;
		for(int i = 1; i < nefre.size() && last > 0;++i){
			if(nefre[i]>= last){
				ans += last - 1;
				--last;
			}
			else{
				ans += nefre[i];
				last = nefre[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}