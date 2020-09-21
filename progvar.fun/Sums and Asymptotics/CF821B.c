#include<stdio.h>
#define ll long long
#define max(x,y)(x > y?x:y)

ll fastSum(ll n){
	return (n*(n+1ll))>>1;
}

int main(){
	ll m,b;
	scanf(" %lld %lld",&m,&b);
	ll ans = 0;
	for(ll i = 0;i <= b;++i){
		ll see = (i*m+1ll)*fastSum(b-i) + (b-i+1ll)*fastSum(i*m);
		ans = max(ans,see);
	}
    printf("%lld\n",ans);
	return 0;
}
