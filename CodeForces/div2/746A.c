#include<stdio.h>
#define min(x,y)(x < y? x:y)

int main(){
	int a,b,c;
	scanf(" %d %d %d",&a,&b,&c);
	int ans = 0;
	int i = 1;
	while(i <= a){
		if((i <<1) > b  || (i<<2) > c)
			break;
		ans = i +(i<<1) + (i<<2);
	//	printf("%d\n",ans);
		++i;
	}
	printf("%d\n",ans);
	return 0;
}