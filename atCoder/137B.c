#include<stdio.h>
#define max(x,y)(x > y? x:y)
#define min(x,y)(x < y? x:y)

int main(){
	int k,x;
	scanf(" %d %d",&k,&x);
	int from = max(-1000000,x-k+1);
	int to = min(1000000,x+k-1);
	for(int i = from; i <= to;++i){
		if(i != from)
			printf(" %d",i);
		else
			printf("%d",i);
	}
	puts("");
	return 0;
}