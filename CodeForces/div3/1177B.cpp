/**
* I'm a loser
*/
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int main(){
	map<ll,ll> trans;
	trans[1] = 1;
	trans[2] = 2;
	trans[3] = 3;
	trans[4] = 4;
	trans[5] = 5;
	trans[6] = 6;
	trans[7] = 7;
	trans[8] = 8;
	trans[9] = 9;
	ll val = 5888890;
	ll i = 1000000;
	vector<ll> nums = {1,2,3,4,5,6,7,8,9};
	while(val <= 1000000000000){
		trans[val] = i;
		nums.push_back(val);
		int dig = 0;
		ll co = i;
		while(co){
			++dig;
			co /= 10;
		}
		i += 1000000;
		val += dig*100000*9;
		//cout << val << endl;
	}
	ll que;
	cin >> que;
	vector<ll>::iterator ind = lower_bound(nums.begin(),nums.end(),que);
	ll index = nums[ind - nums.begin()];
	if(abs(que - nums[ind - nums.begin() - 1]) < abs(que - index))
		index = nums[ind - nums.begin() - 1];
	ll vel = trans[index];
	//cout << "index es " << index << endl;
	if(index == que){
		int dig = 0;
		ll co = vel;
		while(co){
			++dig;
			co /= 10;
		}
		for(int i = 0; i < dig - 1; ++i){
			vel /= 10;
		}
		cout << vel << endl;
		return 0;
	}
	while(true){
		//cout << vel << endl;
		int dig = 0;
		ll co = vel;
		while(co){
			++dig;
			co /= 10;
		}
		if(index + dig > que){
			//cout << index << endl;
			//cout <<" for "  << dig - (que - index) - 1 << endl;
			for(int i = 0; i < dig - (que - index) -1; ++i){
				vel /= 10;
			}
			cout << vel%10 << endl;
			return 0;
		}
		vel++;
		index += dig;
	}
	return 0;
}