#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define min(x,y)(x < y ? x: y)

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int siz;
		scanf(" %d",&siz);
		vector<ll> nums(siz);
		for(int i = 0; i < siz;++i){
			cin >> nums[i];
		}
		sort(nums.begin(),nums.end());
		ll ans = 1000000000;
		for(int i = 0; i < siz-1;++i){
			ll va = nums[i+1] - nums[i];
			ans = min(ans,va);
		}
		cout << ans <<"\n";
	}
	return 0;
}