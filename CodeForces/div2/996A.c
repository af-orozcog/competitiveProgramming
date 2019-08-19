#include<stdio.h>

int main(){
	int num;
	scanf(" %d",&num);
	int vals[] = {1,5,10,20,100};
	int i = 0;
	int m = 4;
	while(num){
		++i;
		while(vals[m] > num){
			--m;
		}
		num -= vals[m];
	}
	printf("%d\n",i);
}