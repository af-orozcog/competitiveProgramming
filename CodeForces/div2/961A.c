/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>
#include<string.h>
#define max(x,y)(x > y? x:y)
#define min(x,y)(x < y?x:y)


short nums[1000];
int N;

int main(){
	int m;
	memset(nums,0,sizeof(nums));
	scanf(" %d %d",&N,&m);
	for(int i = 0; i < m;++i){
		int w;
		scanf(" %d",&w);
		++nums[w-1];
	}
	int ans = 10001;
	for(int i = 0; i < N;++i){
		ans = min(ans,nums[i]);
	}
	printf("%d\n",ans);
}