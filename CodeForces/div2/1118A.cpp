/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll long long
#define min(x,y)(x < y? x:y)

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		ll n,a,b;
		cin >> n >> a >> b;
		ll posi = (n/2)*b + (n%2)*a;
		//cout << posi << endl;
		ll pos2 = n*a;
		cout << min(posi,pos2) << endl;
	}
	return 0;
}