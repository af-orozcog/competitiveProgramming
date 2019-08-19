#include<iostream>
#define ll long long

using namespace std;

int main(){
	ll toSee;
	cin >> toSee;
	ll x1=0;
	ll x2 =1;
	if(toSee == 0){
		cout << "0 0 0" << endl;
		return 0;
	}
	if(toSee == 1){
		cout << "0 0 1" << endl;
		return 0;
	}
	while(true){
		ll temp = x1 + x2;
		if(temp == toSee)
			break;
		x1 = x2;
		x2 = temp;
	}
	cout << 0 << " " <<x1 << " "<< x2<< endl;
	return 0;
}