#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	vector<int> nums(n);
	for(int i = 0; i < n;++i)
		scanf(" %d",&nums[i]);
	sort(nums.begin(),nums.end());
	int k = 1;
	for(int i = 0; i < n;++i){
		if(nums[i] >= k)
			++k;
	}	
	printf("%d\n",k-1);
	return 0;
}