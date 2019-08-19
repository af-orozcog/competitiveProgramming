#include<stdio.h>
#define max(x,y)(x > y? x:y)

int main(){
	int t;
	scanf(" %d",&t);	
	while(t--){
		int n;
		scanf(" %d",&n);
		int nums[n];
		for(int i = 0; i < n;++i)
			scanf(" %d",&nums[i]);
		int ans = 0;
		for(int i = 0; i < n;++i){
			int val;
			scanf(" %d",&val);
			int m = (nums[i]*20)-(val*10);
			ans = max(ans,m);
		}
		printf("%d\n",ans);
	}
	return 0;
}