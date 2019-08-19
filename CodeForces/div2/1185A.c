/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll long long
#define min(x,y) ((x<y)? x:y)
#define max(x,y) ((x>y)? x:y)

using namespace std;

int main(){
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	ll l = min(a,b);
	l = min(l,c);
	ll m = max(a,b);
	m = max(m,c);
	ll middle;
	if(a != l && a != m)
		middle = a;
	else if(b != l && b !=m)
		middle = b;
	else 
		middle = c;
	ll ans = 0;
	if(d - (m - middle) > 0)
		ans += d - (m - middle);
	if(d - (middle - l) > 0)
		ans += d - (middle - l);
	cout << ans << endl;
	return 0;
}