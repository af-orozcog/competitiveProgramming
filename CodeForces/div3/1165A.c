/**
* I'm an Idiot(mf)
*/
#include<stdio.h>

int main(){
	int n,x,y;
	scanf(" %d %d %d",&n,&x,&y);
	char r[n+1];
	scanf(" %s",r);
	int ans = 0;
	int i = n - 1;
	while(i > (n - x-1)){
		if(i == (n-y-1) && r[i] != '1')
			++ans;
		else if(i !=(n-y-1) && r[i] != '0')
			++ans;
		--i;
	}
	printf("%d\n",ans);
	return 0;
}