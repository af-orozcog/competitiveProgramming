/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	int val;
	while(scanf("%d",&val) == 1){
		if(val == 42)
			return 0;
		printf("%d\n",val);
	}
}