/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	int x;
	scanf(" %d",&x);
	if(x % 4 == 1){
		printf("0 A\n");
		return 0;
	}
	if(x % 4 == 3){
		printf("2 A\n");
		return 0;
	}
	if(x % 4 == 2){
		printf("1 B\n");
		return 0;
	}
	printf("1 A\n");
	return 0;
}