#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#define ll long long

using namespace std;

int main(){
	int siz;
	scanf(" %d",&siz);
	vector<int> nums(siz);
	for(int i = 0; i < siz;++i){
		scanf(" %d",&nums[i]);
	}
	sort(nums.begin(),nums.end());
	ll from = nums.size() >> 1;
	if(nums.size() & 1)
		++from;
	--from;
	//cout << from << endl;
	int i = nums[from];
	cout << i << endl;
	return 0;
}