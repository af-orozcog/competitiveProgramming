#include<iostream>
#define ll long long

using namespace std;

ll add(ll m){
	int n = 0;
	while(m){
		n += m % 10;
		m /= 10;
	}
	return 10 - n
}

ll num(int k){
	int n= 1;
	ll s = 19;
	while(n < k){
		s -= 1;
		s+=10;
		if(s % 10 == 0)
			s+= 9;
	}
}
int main(){
	int n;
	cin >> n;
	cout << num(n) << endl;
	return 0;
}