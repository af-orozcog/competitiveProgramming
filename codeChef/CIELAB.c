/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int third = a - b;
	int co = third;
	//while(co % 10 == 0){
	//	co /= 10;
	//}
	int re = co % 10;
	//printf("%d\n",re);
	re = 10 -re;
	--re;
	if(re == 0)
		re = -1;
	printf("%d\n",third + re);
	return 0; 
}
