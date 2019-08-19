/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	int cas;
	scanf("%d",&cas);
	while(cas--){
		char toRead[100001];
		scanf(" %s",toRead);
		int pos = 0;
		for(int i = 0; toRead[i] != '\0';++i){
			if(toRead[i+2] != '\0'){
				//puts("entro aqui?\n");
				if(toRead[i] == '0' && 
					toRead[i+1] == '1'
					&& toRead[i+2] == '0'){
					pos = 1;
					break;
				}
				if(toRead[i] == '1' && 
					toRead[i+1] == '0'
					&& toRead[i+2] == '1'){
					pos = 1;
					break;
				}
			}
			else
				break;
		}
		if(pos)
			printf("Good\n");
		else
			printf("Bad\n");
	}
	return 0;
}