// ALL I DO IS WRONG
#include<stdio.h>

int main(){
	int t;
	scanf(" %d",&t);
	int ans = 0;
	ans += (t/5);
	t -= ((t/5)*5);
	ans += (t/4);
	t -= ((t/4)*4);
	ans += (t/3);
	t -= ((t/3)*3);
	ans += (t>>1);
	t -= ((t>>1)*2);
	ans += t;
	printf("%d\n",ans);
}