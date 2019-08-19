/**
* I'm sorry I was an idiot
*/
#include<stdio.h>
#define min(x,y)(x < y? x:y)

int main(){
	int ones,twos,threes,fours;
	ones = twos = threes = fours = 0;
	int siz;
	scanf(" %d",&siz);
	while(siz--){
		int val;
		scanf(" %d",&val);
		if(val == 1)
			++ones;
		else if(val == 2)
			++twos;
		else if(val == 3)
			++threes;
		else
			++fours;
	}
	int answer = fours;
	int toAdd = min(ones,threes);
	answer += toAdd;
	ones -= toAdd;
	threes -= toAdd;
	answer += threes;
	answer += twos >> 1;
	if(twos & 1){
		answer += 1;
		ones -= min(2,ones);
	}
	answer += ones >> 2;
	if(ones % 4 != 0)
		++answer;
	printf("%d\n",answer);
}