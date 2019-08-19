/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int found(int notes[], int siz, int check){
	for(int i = 0; i < siz;++i){
		if(notes[i] <= check)
			return 0;
	}
	return 1;
}

int main(){
	int cas;
	scanf("%d",&cas);
	while(cas--){
		int siz,val;
		scanf(" %d %d",&siz,&val);
		int total = 0;
		int notes[siz];
		for(int i = 0; i < siz;++i){
			scanf(" %d",(notes + i));
			total += notes[i];
		}
		if(total % val){
			if(found(notes,siz,total % val))
				printf("%d\n",total / val);
			else
				printf("-1\n");
		}
		else
			printf("%d\n",total / val);
	}
	return 0;
}