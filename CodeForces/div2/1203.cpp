#include<iostream>
#define ll long long
#include<map>
#include<cmath>

using namespace std;

ll gcd(ll a,ll b){
	return b == 0? a : gcd(b,a%b);
}

ll primeFac(ll val){
	ll ans = 1;
	for(int i = 2; i <= to;++i){
		if(val % i == 0){
			ans += 2;
			if(val / i == i)
				--ans;
		}
	}
	return ans;
}

int main(){
	int n;
	scanf(" %d",&n);
	ll f;
	cin >> f;
	for(int i = 0; i < n;++i){
		ll val;
		cin >> val;
		f = gcd(f,val);
	}
	cout << primeFac(f) << endl;
	return 0;
}