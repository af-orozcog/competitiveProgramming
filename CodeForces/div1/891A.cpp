#include<iostream>
#define ll long long

using namespace std;

ll gcd(ll a, ll b){
	return b == 0? a: gcd(b, a%b);
}
int main(){
	int n;
	cin >> n;
	ll num[n];
	int one = 0;
	for(int i = 0; i < n;++i){
		cin >> num[i];
		if(num[i] == 1)
			++one;
	}
	int total = 0;
	while(one != n){
		bool posi = false;
		for(int i = 0; i < n-1;++i){
			ll val = gcd(num[i],num[i+1]);
			if(num[i] != num[i+1] && val == 1){
				if(num[i] != 1)
					num[i] = 1;
				else
					num[i+1] = 1;
				posi = true;
				++one;
				++total;
				break;
			}
			if(val != num[i] && val != num[i+1]){
				posi = true;
				num[i] = val;
				++total;
				break;
			}
			//cout << one << endl;
		}
		if(!posi){
			if(n == 2000)
				cout << one << endl;
			cout << -1 << endl;
			return 0;
		}
	}
	cout << total<< endl;
}