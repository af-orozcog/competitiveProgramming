#include<stdio.h>
#include<math.h>
#define min(x,y)(x < y?x:y)

int main(){
	int n,k;
	scanf(" %d %d",&n,&k);
	int nums[n];
	for(int i = 0; i < n;++i)scanf(" %d",&nums[i]);
	int look = (n-(k-1))-1;
	int ans = (look== 0 ? 0:1000000000);
	
	printf("%d\n",ans);
	return 0;
}