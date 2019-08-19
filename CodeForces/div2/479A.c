/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>
#define max(x,y)(x > y? x:y)

int main(){
	int a,b,c;
	scanf(" %d %d %d",&a,&b,&c);
	int ans = a + b +c;
	int ot = a*b*c;
	ans = max(ans,ot);
	ot = (a+b)*c;
	ans = max(ans,ot);
	ot = (a*b)+c;
	ans = max(ans,ot);
	ot = a+(b*c);
	ans = max(ans,ot);
	ot = a*(b+c);
	ans = max(ans,ot);
	printf("%d\n",ans);
	return 0;
}