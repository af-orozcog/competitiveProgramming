#include<iostream>
#include<cmath>
#define ll long long

using namespace std;

int main(){
	ll a,b, steps;
	cin >> a >> b >> steps;
	ll minimum = abs(a) + abs(b);
	if(a == 0 && b == 0 && steps%2 == 0){
		cout << "Yes" << endl;
		return 0;
	}
	if (a == 0 && b == 0 && steps%2 != 0){
		cout << "No" << endl;
		return 0;
	}
	if(steps - minimum < 0){
		cout << "No" << endl;
		return 0;
	}
	if((steps - minimum)%2 != 0){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}