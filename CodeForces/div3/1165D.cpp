/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

vector<ll> allDivisors(ll val){
	vector<ll> ans;
	for(ll i = 2; i <= sqrt(val);++i){
		if(val % i == 0){
			ll toAdd1 = i;
			ll toAdd2 = val / i;
			if(toAdd1 == toAdd2)
				ans.push_back(toAdd1);
			else{
				ans.push_back(toAdd1);
				ans.push_back(toAdd2);
			}
		}
	}
	sort(ans.begin(),ans.end());
	return ans;
}

int main(){
	int que;
	cin >> que;
	while(que--){
		int siz;
		cin >> siz;
		vector<ll> nums(siz);
		for(int i = 0; i < siz;++i){
			cin >> nums[i];
		}
		sort(nums.begin(),nums.end());
		ll posVal = nums[nums.size()-1] * nums[0];
		vector<ll> toCompare = allDivisors(posVal);
		if(toCompare.size() != nums.size()){
			cout << -1 << endl;
			continue;
		}
		bool posi = true;
		for(int i = 0; i < toCompare.size();++i){
			if(toCompare[i] != nums[i]){
				posi = false;
				break;
			}
		}
		if(!posi)
			cout << -1 << endl;
		else
			cout << posVal << endl;
	}
	return 0;
}