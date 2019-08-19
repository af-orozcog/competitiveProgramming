#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int main(){
	int siz;
	scanf(" %d",&siz);
	ll sum = 0;
	vector<ll> nums(siz);
	for(int i = 0; i < siz;++i){
		ll val;
		cin >> val;
		sum += val;
		nums[i] = val;
	}
	sort(nums.begin(),nums.end());
	reverse(nums.begin(),nums.end());
	int i = 0, j = 1;
	while(i < siz && j < siz){
		ll less = min(nums[i],nums[j]);
		nums[i] -= less;
		nums[j] -= less;
		if(nums[i] == 0){
			if(nums[j] == 0){
				i = j +1;
			}
			else{
				i = j;
			}
			++j;
		}
		else
			++j;
	}
	if(i == siz)
		puts("YES");
	else
		puts("NO");
	return 0;
}