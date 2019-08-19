/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>
#include<string.h>

int main(){
	int done[100];
	memset(done,-1,sizeof(done));
	int siz;
	scanf(" %d",&siz);
	int p1;
	scanf(" %d",&p1);
	while(p1--){
		int val;
		scanf(" %d",&val);
		done[val-1] = 1;
	}
	scanf(" %d",&p1);
	while(p1--){
		int val;
		scanf(" %d",&val);
		done[val-1] = 1;
	}
	int posi = 1;
	for(int i = 0; i < siz;++i){
		if(done[i] == -1){
			posi = 0;
			break;
		}
	}
	if(posi)
		puts("I become the guy.");
	else
		puts("Oh, my keyboard!");
	return 0;
}