/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<ll> nums(2*n);
	for(int i = 0; i < 2*n;++i){
		cin >> nums[i];
	}
	sort(nums.begin(),nums.end());
	ll sum1 = 0;
	for(int i = 0; i < n;++i){
		sum1 += nums[i]; 
	}
	ll sum2 = 0;
	for(int i = n; i < 2*n;++i){
		sum2 += nums[i];
	}
	if(sum1 == sum2){
		puts("-1");
		return 0;
	}
	for(int i = 0; i < 2*n;++i){
		if(i == 0)
			cout << nums[i];
		else
			cout << " " << nums[i];
	}
	cout << endl;
	return 0;
}