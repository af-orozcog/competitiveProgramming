/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	int a,b,c,d,e;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	int sum = a + b + c + d + e;
	if(sum % 5 != 0 || sum == 0){
		printf("-1\n");
		return 0;
	}
	int ans = sum / 5;
	printf("%d\n",ans);
	return 0;
}	