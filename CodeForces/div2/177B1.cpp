/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cmath>
#define ll long long

using namespace std;

ll smallest(ll val){
	ll to = sqrt(val);
	for(ll i = 2; i <=to;++i){
		if(val % i == 0)
			return i;
	}
	return val;
}

int main(){
	ll val;
	cin >> val;
	ll total = 0;
	while(val != 1){
		total += val;
		val /= smallest(val);
	}
	cout << total +1 << endl;
	return 0;
}