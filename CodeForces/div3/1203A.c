#include<stdio.h>

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int n;
		scanf(" %d",&n);
		int nums[n];
		for(int i = 0; i < n;++i)
			scanf(" %d",&nums[i]);
		int first = nums[0];
		int po = 1;
		for(int i = 1; i < n && po;++i){
			if(nums[i] -1 != first && (nums[i] != 1 || first != n))
				po = 0;
			first = nums[i];
		}
		if(po){
			puts("YES");
			continue;
		}
		first = nums[0];
		po = 1;
		for(int i = 1; i < n && po;++i){
			if(nums[i] + 1 != first && (first != 1 || nums[i] != n))
				po = 0;
			first = nums[i];
		}
		if(po)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}