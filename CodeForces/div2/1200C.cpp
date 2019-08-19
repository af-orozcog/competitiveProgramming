#include<iostream>
#define ll long long

using namespace std;

ll gcd(ll a, ll b){
	return b == 0? a: gcd(b, a %b); 
}

ll id(ll n, ll m, ll sx,ll sy, ll imp){
	ll divn = n / imp;
	ll divm = m / imp;
	ll id1;
	if(sx == 1){
		if(sy % divn)
			id1 = (sy /divn) + 1;
		else
			id1 = sy/divn;
	}
	else{
		if(sy % divm)
			id1 = (sy/divm) + 1;
		else
			id1 = (sy/divm);
	}
	return id1;
}

int main(){
	ll n,m,q;
	cin >> n >> m >> q;
	ll imp = gcd(n,m);
	while(q--){
		ll sx,sy,ex,ey;
		cin >> sx >> sy >> ex >> ey;
		if(gcd(n,m) == 1){
			puts("YES");
			continue;
		}
		ll id1 = id(n,m,sx,sy,imp);
		//cout << id1 << endl;
		ll id2 = id(n,m,ex,ey,imp);
		//cout << id2 << endl;
		if(id1 == id2)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}