#include<iostream>
#define ll long long

using namespace std;

ll many(ll n){
	ll ans = 0;
	if(n== 1){
		n = (3*n)+1;
		++ans;
	}
	while(n!= 1){
		++ans;
		if(n&1)
			n = (3*n)+1;
		else
			n = n/2;
	}
	return ans;
}

int main(){
	while(1){
		ll l,h;
		scanf(" %lld %lld",&l,&h);
		if(l == 0 && h == 0)
			break;
		if(l > h){
			ll temp = l;
			l = h;
			h = temp;
		}
		//cout << l << " " << h << endl;
		ll val = 0;
		ll ans = 0;
		for(ll i = l; i <= h;++i){
			ll check = many(i);
			if(check > val){
				ans = i;
				val = check;
			}
		}
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",l,h,ans,val);
	}
	return 0;
}