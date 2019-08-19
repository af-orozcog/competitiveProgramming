/**
* I'm sorry I was an idiot
*/
#include<stdio.h>
#define max(x,y)(x > y? x:y)

int main(){
	int siz;
	scanf(" %d",&siz);
	int nums[siz];
	int valmax = 0;
	for(int i = 0; i < siz;++i){
		scanf(" %d",&nums[i]);
		valmax = max(nums[i],valmax);
	}
	int ans = 0;
	for(int i = 0; i < siz;++i){
		ans += valmax - nums[i];
	}
	printf("%d\n",ans);
	return 0;
}