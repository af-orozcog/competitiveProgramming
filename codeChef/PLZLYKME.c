/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>
#define ll long long

int main(){
	int cas;
	scanf("%d",&cas);
	while(cas--){
		ll l,d,s,c;
		scanf(" %lld %lld %lld %lld",&l,&d,&s,&c);
		ll last = s;
		for(int i = 1; i < d;++i){
			ll val = last + (last*c);
			last = val;
			if(last >= l)
				break;
		}
		if(last >= l)
			puts("ALIVE AND KICKING");
		else
			puts("DEAD AND ROTTING");
	}
	return 0;
}