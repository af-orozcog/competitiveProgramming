#include<iostream>
#define ll long long
#define abs(x)(x < 0? -x:x)
#define min(x,y)(x < y?x:y)

using namespace std;

int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	ll add;
	if(a == b)
		add = (a<<1);
	else
		add = (min(a,b)<<1) +1;
	cout << (c<<1) + add << endl;
	return 0; 
}