/**
* I'm sorry I was an Idiot
*/ 
#include<iostream>
#include<bitset>
#define ll unsigned long long
#include<cmath>
#include<vector>

using namespace std;

bool prime(ll val){
	if(val <= 1) return false;
	if(val <= 3) return true;
	if(val %2 == 0 || val % 3 == 0)
		return false;
	for(ll i = 5; i*i <= val;i+=6){
		if(val % i == 0 || val%(i+2) == 0)
			return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int cas;
	cin >> cas;
	while(cas--){
		ll va1,va2;
		cin >> va1 >> va2;
		for(ll i = va1; i <= va2;++i){
			if(prime(i))
				cout << i<< endl;
		}
		cout << endl;
	}
	return 0;
}