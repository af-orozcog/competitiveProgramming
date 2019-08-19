/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll long long

using namespace std;

int gcd(ll a,ll b){
	return b == 0? a: gcd(b,a%b);
}

int main(){
	ll n;
	cin >> n;
	ll f = n;
	ll i = n;
	ll s;
	for(; i > 0;--i){
		//cout << i << endl;
		//cout << gcd(f,i) << endl;
		if(gcd(f,i) == 1){
			s = i;
			//cout << "s es " << s << endl;
			break;
		}
	}
	ll t;
	for(; i > 0;--i){
		if(gcd(f,i) == 1 && gcd(s,i) == 1){
			t = i;
			break;
		}
	}
	//cout << f<<endl;
	//cout << s << endl;
	//cout << t << endl;
	cout << f*s*t << endl;
	return 0;
}