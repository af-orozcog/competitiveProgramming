#include<iostream>
#include<cmath>
#define ll unsigned long long

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll X;
		cin >> X;
		ll i = 1;
		ll sum = 0;
		ll com = X*X;
		ll ans = 1;
		while(sum < com){
			i = sqrt(sum) + 1;
			//cout << "i es "<<i << endl;
			if(i == X)
				break;
			sum += i*i;
			if(sum < com)
				++ans;
		}
		cout << ans << endl;
	}
	return 0;
}