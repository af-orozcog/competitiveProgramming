/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>
#define ll long long 

int main(){
	int cas;
	scanf(" %d",&cas);
	while(cas--){
		ll x,y,k;
		scanf(" %lld %lld %lld",&x,&y,&k);
		ll toCheck = x +y;
		toCheck = toCheck / k;
		if(toCheck & 1)
			puts("Paja");
		else
			puts("Chef");
	}
	return 0;
}