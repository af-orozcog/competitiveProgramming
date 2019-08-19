#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define min(x,y)(x < y?x:y)

using namespace std;

int main(){
	ll n,k;
	cin >> n >>k;
	vector<ll> nums(n);
	for(int i = 0; i < n;++i)
		cin >> nums[i];
	sort(nums.begin(),nums.end());
	int index = ((int)n) >> 1;
	int sum = 1;
	int m = index +1;
	ll ans = -1;
	while(k > 0 && m < n){
		ll toAdd = nums[m] - nums[m-1];
		toAdd = min(toAdd*sum,k);
		k -= toAdd;
		nums[m-1] += toAdd/sum;
		++m;
		++sum;
	}
	nums[m-1] += k / sum;
	cout << nums[m-1] << endl;
	return 0;
}