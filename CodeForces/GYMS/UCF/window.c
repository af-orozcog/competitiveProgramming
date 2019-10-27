#include<stdio.h>
#define max(x,y)(x > y?x:y)

int main(){
	int w,h,d;
	scanf(" %d %d %d",&w,&h,&d);
	printf("%d\n",max(0,w-(d<<1))*max(0,h-(d<<1)));
	return 0;
}