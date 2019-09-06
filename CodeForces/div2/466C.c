#include<stdio.h>
#define ll long long

int main(){
	int n;
	scanf(" %d",&n);
	ll nums[n];
	scanf(" %I64d",&nums[0]);
	for(int i = 1; i < n;++i){
		ll val;
		scanf(" %I64d",&val);
		nums[i] = nums[i-1] + val;
	}
	if(nums[n-1] % 3 != 0){
		puts("0");
		return 0;
	}
	
	printf("%d\n", ans);
	return 0;
}