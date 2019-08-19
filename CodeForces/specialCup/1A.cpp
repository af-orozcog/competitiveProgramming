/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll long long
#include<cmath>

using namespace std;

int main(){
	ll n,m,a;
	cin >> n >> m >> a;
	if(n%a == 0 && m % a == 0){
		cout << (n*m)/(a*a) << endl;
		return 0;
	}
	if((n*m) < (a*a)){
		cout << 1 << endl;
		return 0;
	}
	double one = n/(double)a;
	double two = m/(double)a;
	ll on = ceil(one);
	ll tw = ceil(two);
	cout << on * tw << endl;
	return 0;
}