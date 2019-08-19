#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

int main(){
	ll H,rounds;
	cin >> H >> rounds;
	ll rounVal[rounds];
	ll cas = 0;
	for(ll i = 0; i < rounds; i++){
		ll val;
		cin >> val;
		rounVal[i] = val;
		cas += val;
	}
	ll copH = H;
	for(ll i = 0; i < cas;i++){
		copH += rounVal[i];
		if(copH <= 0){
			cout << i + 1 << endl;
			return 0;
		}
	}
	if(cas >= 0){
		cout << -1 << endl;
	}
	ll div = H / cas;
	ll minutes;
	H += (div)*cas;
	minutes = (div-1) * rounds;
	cout << H << endl;
	for(ll i = 0; i < rounds; i++){
		H += rounVal[i];
		if(copH <= 0){
			
	return 0;
}