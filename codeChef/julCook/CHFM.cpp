/**
* I'm sorry I was an Idiot
*/
#include<vector>
#include<algorithm>
#include<iostream>
#define ll long long
#include<cmath>

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int siz;
		cin >> siz;
		vector<ll> nums(siz);
		ll sum = 0;
		for(int i = 0; i < siz;++i){
			cin >> nums[i];
			sum += nums[i];
		}
		ll ans = -1;
		for(int i = 0; i < siz;++i){
			ll pos = sum - nums[i];
			if(pos % (siz-1) == 0){
				ll search = pos / (siz-1);
				if(search == nums[i]){
					ans = i+1;
					break;
				}
			}
		}
		if(ans != -1)
			cout << ans << endl;
		else
			cout << "Impossible\n";
	}
}