/**
* I'm very sorry :(
*/
#include<stdio.h>
#define min(x,y)(x < y?x:y)
#define max(x,y)(x > y?x:y)

int main(){
	int b,g,n;
	scanf(" %d %d %d",&b,&g,&n);
	int neG = min(n,g);
	int neB = min(b,n);
	printf("%d\n",min(neG+1,neB+1));
	return 0;
}