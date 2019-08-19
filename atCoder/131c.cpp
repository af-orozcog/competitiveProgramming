/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll unsigned long long

using namespace std;

ll gcd(ll a,ll b){
	return b == 0 ? a: gcd(b, a % b);
}

int main(){
	ll a,b,c,d;
	cin >> a >> b >> c >> d;

	ll posC = (b/c) - (a/ c);

	if(a % c == 0)
		++posC;

	ll posD = (b/d) - (a/d);
	if(a % d == 0)
		++posD;

	ll lcm = (c*d)/gcd(c,d);
	ll posLC = (b/lcm) - (a/ lcm);
	if(a % lcm == 0)
		++posLC;
	ll ans = posC + posD - posLC;
	//cout << posC << " " << posD << endl;
	//cout << ans << endl;
	ans = (b-a + 1) - ans; 
	cout << ans << endl;
	return 0;
}