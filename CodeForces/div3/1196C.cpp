#include<iostream>
#define min(x,y)(x < y? x: y)
#define max(x,y)(x > y? x:y)
#define ll long long

using namespace std;

bool intersec(ll a, ll b, ll *x, ll *y){
	if(b < (*x))
		return false;
	if((*y) < a)
		return false;
	ll neL = max(a,(*x));
	ll neR = min(b,(*y));
	*x = neL;
	*y = neR;
	return true;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll y2 = 100000,y1 = -100000;
		ll x1 = -100000, x2 = 100000;
		int n;
		cin >> n;
		bool posi = true;
		while(n--){
			ll x,y;
			cin >> x >> y;
			ll hi,lo,ri,le;
			short f1;
			cin >> f1;
			if(f1)
				le = -100000;
			else
				le = x;
			short f2;
			cin >> f2;
			if(f2)
				hi = 100000;
			else
				hi = y;
			short f3;
			cin >> f3;
			if(f3)
				ri = 100000;
			else
				ri = x;
			short f4;
			cin >> f4;
			if(f4)
				lo = -100000;
			else
				lo = y;
			if(!intersec(lo,hi,&y1,&y2))
				posi = false;
			if(!intersec(le,ri,&x1,&x2))
				posi = false;
		}
		if(posi){
			cout << 1 << " " << x1 << " " << y1 << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}