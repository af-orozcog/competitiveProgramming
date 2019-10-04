#include<stdio.h>
#define min(x,y)(x < y? x:y)

int main(){
	int b,g,n;
	scanf(" %d %d %d",&b,&g,&n);
	int i = min(b,n);
	for(; i >= 0;--i){
		if(n-i >= min(n,g))
			break;
	}
	printf("%d\n",(min(b,n)-i)+1);
	return 0;
}