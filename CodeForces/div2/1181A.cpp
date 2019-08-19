/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll long long
#define min(x,y)(x<y? x:y)
#define max(x,y)(x>y? x:y)

using namespace std;

int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	ll one = a / c;
	ll two = b / c;
	ll oneR = a % c;
	ll twoR = b % c;
	ll max = max(oneR,twoR);
	ll min = min(oneR,twoR);
	if(c - max <= min){
		one += 1;
		cout << one + two << " " << c - max << endl;
	}
	else
		cout << one + two <<" " <<0 << endl;
	return 0;
}