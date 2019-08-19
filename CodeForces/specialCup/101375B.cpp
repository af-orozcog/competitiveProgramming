/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll long long

using namespace std;

int main(){
	ll x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll neX1 = x1*x1;
	//cout << neX1 << endl;
	ll neY1 = y1*y1;
	//cout << neY1 << endl;
	ll neX2 = x2*x2;
	//cout << neX2 << endl;
	ll neY2 = y2*y2;
	//cout << neY2 << endl;
	if((neX1 +neY1) < (neX2 + neY2))
		puts("Russo");
	else if((neX1 + neY1) > (neX2 + neY2))
		puts("Wil");
	else
		puts("Empate");
	return 0;
}