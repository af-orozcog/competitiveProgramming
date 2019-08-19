#include<stdio.h>
#define max(x,y)(x > y?x:y)

int main(){
	int a,b;
	scanf(" %d %d",&a,&b);
	int ans = a*b;
	ans = max(a-b,ans);
	ans = max(a+b,ans);
	printf("%d\n",ans);
	return 0;
}