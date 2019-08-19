/**
* I'm sorry I was an Idiot 
*/
#include<stdio.h>

int main(){
	int a,b;
	scanf( "%d %d",&a,&b);
	if(b < a){
		int temp = a;
		a = b;
		b = temp;
	}
	int totalMin = 0;
	//int m = 0;
	while(1){
		if(a <= 2 && b == 2){
			++totalMin;
			break;
		}
		if(a < 2 && b < 2)
			break;
		int max = b >> 1;
		if(b % 2 == 0)
			--max;
		//printf("max es %d\n",max);
		totalMin += max;
		a += max;
		b -= (max) << 1;
		//printf("%d %d\n",a,b);
		int temp = a;
		a = b;
		b = temp;
		//++m;
	}
	printf("%d\n",totalMin);
	return 0;
}