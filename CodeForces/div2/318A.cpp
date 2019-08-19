/**
* I'm an idiot
*/
#include<iostream>
#define ll long long

using namespace std;

int main(){
	ll val,pos;
	cin >> val >> pos;
	ll mid = val >> 1;
	if(val & 1 == 1){
		mid += 1;
	}
	ll answer;
	if(pos <= mid){
		answer = 1 + ((pos-1) << 1);
	}
	else{
		pos -= mid;
		answer = ((pos) << 1);
	}
	cout << answer << endl;
	return 0;
}