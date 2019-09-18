#include<stdio.h>
#define max(x,y)(x > y? x:y)
#define min(x,y)(x < y? x:y)

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int x,y,k;
		scanf(" %d %d %d",&x,&y,&k);
		int xle = max(x-k,1);
		int xri = min(x+k,8);
		int up = max(1,y-k);
		int down = min(8,y+k);
		printf("%d\n", ((xri-xle)+1)*((down - up)+1));
	}
	return 0;
}