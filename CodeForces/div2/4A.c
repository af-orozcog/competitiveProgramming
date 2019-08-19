/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	int w;
	scanf("%d",&w);
	if(w <= 2 || w & 1){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}