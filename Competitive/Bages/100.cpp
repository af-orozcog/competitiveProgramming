/**
* I'm sorry I was an Idiot
*/
#include<iostream>
using namespace std;

int operations(int val){
	int total = 1;
	while(val != 1){
		if(val & 1){
			//cout << val << endl;
			val = 3*val + 1;
		}
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
		int coi = i;
		int coj = j;
		if(j < i){
			int temp = i;
			i = j;
			j = temp;
		}
		int max = 0;
		for(int m = i; m <= j;++m){
			int toCheck = operations(m);
			if(toCheck > max)
				max = toCheck;
		}
		printf("%d %d %d\n",coi,coj,max);
	}
	return 0;
}