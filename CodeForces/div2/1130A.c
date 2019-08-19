/**
* I'm an Idiot
*/
#include<stdio.h>

int main(){
	int siz;
	scanf("%d",&siz);
	int G = siz & 1 ? ((siz>>1)+1): (siz>>1);
	int pos = 0;
	int neg = 0;
	for(int i = 0; i < siz;++i){
		int val;
		scanf(" %d",&val);
		if(val > 0)
			++pos;
		else if(val < 0)
			++neg;
	}
	if(pos >= G)
		puts("1");
	else{
		if(neg >= G)
			puts("-1");
		else
			puts("0");
	}
	return 0;
}