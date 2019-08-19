#include<stdio.h>

int main(){
	int n;
	scanf(" %d",&n);
	int nums[n];
	for(int i = 0; i < n;++i)
		scanf(" %d",&nums[i]);
	int min = 0;
	int pos = 1;
	for(int i = n-2; i >= 0;--i){
		if(nums[i+1] < nums[i])
			--nums[i];
	}
	for(int i = 0; i < n-1;++i){
		if(nums[i+1] < nums[i])
			pos = 0;
	}
	if(pos)
		puts("Yes");
	else
		puts("No");
	return 0;
}