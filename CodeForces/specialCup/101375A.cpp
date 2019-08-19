/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll long long

using namespace std;

int main(){
	ll n;
	cin >> n;
	--n;
	ll ans = (n*(n+1)) >> 1;
	cout << ans + 1 << endl;
	return 0;
}