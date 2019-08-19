/**
* I'm sorry I was an Idiot
*/
#include<iostream>
using namespace std;

int operations(int val){
	int total = 1;
	while(val != 1){
		if(val & 1)
			val = 3*val + 1;
		else
			val = val >> 1;
		++total;
	}
	return total;
}

int main(){
	int i,j;
	//puts("lil");
	while(cin >> i >>j){
		//printf("lel");
		int max = 0;
		for(int m = i; m <= j;++m){
			int toCheck = operations(m);
			if(toCheck > max)
				max = toCheck;
		}
		printf("%d %d %d\n",i,j,max);
	}
	return 0;
}