#include<stdio.h>
#define ll long long

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		ll a,b;scanf("%lld %lld",&a,&b);
		printf("%lld %lld\n", (b != 0 ? a/b: 0),(b != 0 ? a%b:a));
	}
	return 0;
}