/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>
#define ll unsigned long long

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b,a%b);
}

int main(){
	int cas;
	scanf("%d",&cas);
	while(cas--){
		ll k,n,a,b;
		scanf("%llu %llu %llu %llu",&n,&a,&b,&k);
		ll mcm = (a*b)/gcd(a,b);
		ll posA = n / a;
		ll posB = n / b;
		ll less = n / mcm;
		if((posA + posB - (less << 1)) >= k)
			printf("Win\n");
		else
			printf("Lose\n");
	}
	return 0;
}