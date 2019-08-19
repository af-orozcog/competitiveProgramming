/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	int toCheck;
	scanf(" %d",&toCheck);
	int digitSum = 0;
	int co = toCheck;
	int lastDi = toCheck % 10;
	while(co != 0){
		digitSum += co% 10;
		co/= 10;
	}
	if(digitSum % 4 == 0){
		printf("%d\n",toCheck);
		return 0;
	}
	int toAdd = 4 - (digitSum % 4);
	co = toCheck;
	while(1){
		co = co + toAdd;
		int secCo = co;
		digitSum = 0;
		while(secCo != 0){
			digitSum += secCo% 10;
			secCo/= 10;
		}
		//printf(" here %d\n", digitSum);
		if(digitSum % 4 == 0)
			break;
		toAdd = 4 - (digitSum % 4);
	}
	printf("%d\n", co);
	return 0;
}