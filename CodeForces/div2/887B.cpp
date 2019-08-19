#include<iostream>
#define ll long long
#include<cmath>

using namespace std;

ll digits(ll num){
	ll i = 0;
	while(num){
		++i;
		num /= 10;
	}
	return i;
}

ll realVal(ll num){
	ll d = pow(10,digits(num));
	ll ans = num * d;
	d /= 10;
	while(num){
		ans += (num % 10) * d;
		num /= 10;
		d /= 10;
	}
	return ans;
}

int main(){
	ll k,p;
	cin >> k >>p;
	ll co[] = {11,22,33,44,55,66,77,88,99};
	co[0] = co[0] % p;
	for(int i = 1; i < 9;++i){
		co[i] += (co[i-1] %p);
		co[i] = co[i] %p; 
	}
	if(k < 10){
		cout << co[k-1] << endl;
		return 0;
	}
	ll c = 9;
	ll nn = 10;
	ll ans = co[8];
	while(c < k){
		ans += (realVal(nn) % p);
		ans = ans % p;
		//cout << realVal(nn) << endl;
		++nn;
		++c;
	}
	cout << ans << endl;
	return 0;
}