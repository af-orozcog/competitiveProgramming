#include<stdio.h>

int main(){
	int n;
	scanf(" %d",&n);
	int nums[n];
	for(int i = 0; i < n;++i)
		scanf(" %d",&nums[i]);
	int max = 0;
	int bestBe = 0;
	int bestEnd = 0;
	int be = 0;
	int sum = 0;
	for(int i = 0; i < n;++i){
		if(nums[i] == 1)
			--sum;
		else 
			++sum;
		if(sum < 0){
			sum = 0;
			be = i+1;
			continue;
		}
		if(sum > max){
			bestBe = be;
			bestEnd = i;
			max = sum;
		}
	}
	int ans = 0;
	for(int i = 0; i < n;++i){
		if(i >= bestBe && i <= bestEnd && nums[i] == 0)
			++ans;
		else if(i < bestBe || i > bestEnd){
			if(nums[i] == 1)
				++ans;
		}
	}
	printf("%d\n",ans);
}