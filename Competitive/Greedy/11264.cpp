/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int siz;
		cin >> siz;
		vector<ll> nums(siz);
		for(int i = 0; i < siz;++i){
			cin >> nums[i];
		}
		ll ans = 2;
		ll total = nums[0];
		for(int i = 1;i < nums.size() - 1;++i){
			int neTotal = total+nums[i];
			//vector<ll>::iterator low = lower_bound(nums.begin(),nums.end(),neTotal);
			if(neTotal < nums[i+1]){
				total = neTotal;
				++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}