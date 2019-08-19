/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	int n,m,k;
	scanf(" %d %d %d",&n,&m,&k);
	if(n > m || n > k)
		puts("No");
	else
		puts("Yes");
	return 0;
}