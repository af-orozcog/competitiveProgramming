#include<iostream>
#define ll long long

using namespace std;

int main(){
	ll val;
	cin >> val;
	ll toSub = val - 1;
	ll total = val;
	while(toSub != 0){
		total += (val-toSub)*toSub;
		toSub--;
	} 
	cout << total << endl;
}