/**
* I'm an idiot
*/
#include<iostream>
#define ll long long
#include<vector>
using namespace std;
typedef vector<ll> vl;
vl four;
vl six;
vl eig;


void fo(){
	if(four.size() >= 1)
		return;
	for(ll i = 1001; i < 9999; i++){
		int co = i;
		int a = 0,b = 0;
		for(int j = 0; j < 2;j++){
			a += (co % 10) *(10 * j);
			if(j != 1)
				co /= 10;
		}
		for(int j = 0; j < 2;j++){
			b += (co % 10) *(10 * j);
			co /= 10;
		}
		cout << "a es: "<< a << " b es " << b << " i es " << i << endl;
		if(i%(a+b) == 0 && i/(a+b) == (a+b))
			four.push_back(i);
	}
}
void si(){
	if(six.size() >= 1)
		return;
	for(ll i = 100001; i < 999999; i++){
		int co = i;
		int a = 0,b = 0;
		for(int j = 0; j < 3;j++){
			a += (co % 10) *(10 * j);
			co /= 10;
		}
		for(int j = 0; j < 3;j++){
			b += (co % 10) *(10 * j);
			co /= 10;
		}
		if(i/(a+b) == (a+b))
			six.push_back(i);
	}
}
void ei(){
	if(eig.size() >= 1)
		return;
	for(ll i = 10000000; i < 99999999; i++){
		int co = i;
		int a = 0,b = 0;
		for(int j = 0; j < 4;j++){
			a += (co % 10) *(10 * j);
			co /= 10;
		}
		for(int j = 0; j < 4;j++){
			b += (co % 10) *(10 * j);
			co /= 10;
		}
		if(i/(a+b) == (a+b))
			eig.push_back(i);
	}
}

int main(){
	int val;
	while(cin >> val){
		for(int i = 0; i < val;i++){
			cout << 0;
		}
		cout << endl;
		for(int i = 0; i < val/2;i++){
			cout << 0;
		}
		cout << 1 << endl;
		if(val == 2){
			cout << 81 << endl;
			continue;
		}
		if(val == 4){ 
			fo();
			for(int i = 0; i< four.size(); i++){
				cout << four[i] << endl;
			}
			continue;
		}
		if(val == 6){ 
			si();
			for(int i = 0; i< six.size(); i++){
				cout << six[i] << endl;
			}
			continue;
		}
		if(val == 8){ 
			ei();
			for(int i = 0; i< eig.size(); i++){
				cout << eig[i] << endl;
			}
			continue;
		}
	}
	return 0;
}