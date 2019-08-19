/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	int siz;
	scanf("%d",&siz);
	char toRead[siz+1];
	scanf(" %s",toRead);
	int A = 0;
	int D = 0;
	int i = 0;
	while(toRead[i] != '\0'){
		if(toRead[i] == 'A')
			++A;
		else
			++D;
		++i;
	}
	if(A == D)
		puts("Friendship");
	else if(A > D)
		puts("Anton");
	else
		puts("Danik");
	return 0;
}