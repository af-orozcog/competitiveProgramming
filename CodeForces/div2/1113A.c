/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>
#define min(x,y)(x < y? x:y)

int main(){
	int cit,fu;
	scanf(" %d %d",&cit,&fu);
	--cit;
	int initial = min(cit,fu);
	int cost = initial;
	for(int i = 2; i <= cit;++i){
		--initial;
		if(initial >=  cit - (i-1)){
			//printf("%d\n",initial)
			break;
		}
		cost += i;
		++initial;
	}
	printf("%d\n",cost);
	return 0;
}