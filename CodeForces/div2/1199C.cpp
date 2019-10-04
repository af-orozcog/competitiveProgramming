#include<iostream>
#include<set>
#include<cmath>
#include<algorithm>
#define min(x,y)(x < y?x:y)

using namespace std;


int main(){
	int n,I;
	scanf(" %d %d",&n,&I);
	I = (I<<3)/n;
	//cout << I << endl;
	int chan = 1000000000;
	if(I < 32)
		chan = (1<<I);
	int nums[n];
	set<int> uni;
	for(int i = 0; i < n;++i){
		scanf(" %d",&nums[i]);
		uni.insert(nums[i]);
	}
	sort(nums,nums+n);
	int min = nums[0];
	int max = nums[n-1];
	int l = min;
	int ans = 1000000000;
	if(l +(chan-1) >= max){
		puts("0");
		return 0;
	}
	for(auto va: uni){
		if(va +(chan-1) > max)
			break;
		int ind1 = lower_bound(nums,nums+n,va)-nums;
		int ind2 = upper_bound(nums,nums+n,va+(chan-1))-nums;
		int changed = ind1 + (n-ind2);
		ans = min(ans,changed);
	}
	printf("%d\n", ans);
	return 0;
}