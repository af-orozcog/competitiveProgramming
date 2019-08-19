/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	char toRead[5];
	scanf("%s",toRead);
	int bad = 0;
	for(int i = 0; i < 3;++i){
		if(toRead[i] == toRead[i+1]){
			bad = 1;
			break;
		}
	}
	if(bad)
		puts("Bad");
	else
		puts("Good");
	return 0;
}