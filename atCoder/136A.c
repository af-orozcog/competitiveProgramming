#include<stdio.h>
#define max(x,y)(x > y?x:y)

int main(){
	int a,b,c;
	scanf(" %d %d %d",&a,&b,&c);
	a -= b;
	c -= a;
	printf("%d\n",max(0,c));
	return 0;
}