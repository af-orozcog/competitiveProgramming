#include<iostream>
#define ll long long
#define max(x,y)(x > y? x:y)

using namespace std;

int main(){
	ll val;
	cin >> val;
	int count = 0;
	while(val){
		ll temp = val;
		ll maxx = 0;
		while(temp){
			ll dig = temp %10;
			maxx = max(dig,maxx);
			temp /= 10;
		}
		val -= maxx;
		++count;
	}
	cout << count << endl;
}