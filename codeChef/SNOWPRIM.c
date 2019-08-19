/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>
#define ll long long

int main(){
	ll cas;
	scanf(" %lld",&cas);
	while(cas--){
		ll val;
		scanf(" %lld",&val);
		if(val < 2)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}