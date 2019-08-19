/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>
#define ll long long

int main(){
	int cas;
	scanf(" %d",&cas);
	while(cas--){
		int G;
		scanf(" %d",&G);
		while(G--){
			ll I,N,Q;
			scanf(" %lld %lld %lld",&I,&N,&Q);
			int ones;
			int zero;
			if(N % 2 == 0){
				ones = N >> 1;
				zero = N >> 1;
			}
			else{
				if(I == 1){
					ones = N >> 1;
					zero = N - ones;
				}
				else{
					zero = N >> 1;
					ones = N - zero;
				}
			}
			if(Q == 1)
				printf("%d\n",ones);
			else
				printf("%d\n",zero);
		}
	}
	return 0;
}