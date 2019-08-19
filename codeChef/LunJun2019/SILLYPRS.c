/**
* I'm sorry I was an Idiot 
*/
#include<stdio.h>
#define ll long long

int main(){
	int cas;
	scanf(" %d",&cas);
	while(cas--){
		ll N;
		scanf(" %lld",&N);
		ll sum1 = 0;
		ll sum2 = 0;
		for(int i = 0;i < N;++i){
			ll val;
			scanf(" %lld",&val);
			sum1 += val;
		}
		for(int i = 0;i < N;++i){
			ll val;
			scanf(" %lld",&val);
			sum2 += val;
		}
		printf("%lld\n",(sum1/2) + (sum2/2));
	}
	return 0;
}