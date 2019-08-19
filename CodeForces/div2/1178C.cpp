#include<iostream>
#define ll long long 
#define M 998244353

using namespace std;

int main(){
	ll w,h;
	cin >> w >> h;
	ll ans = 4;
	for(int i = 1; i < w;++i){
		ans = ans << 1;
		ans = ans % M;
	}
	for(int i = 1;i < h;++i){
		ans = ans << 1;
		ans = ans % M;
	}
	cout << ans << endl;
}