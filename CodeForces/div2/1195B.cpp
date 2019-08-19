/**
* about to lose ranking
*/
#include<iostream>
#include<cmath>
#define ll long long

using namespace std;


/*ll added(ll c){
	ll see = c << 3;
	++see;
	see = sqrt(see);
	--see;
	return (see >> 1);
}*/

int main(){
	ll n,k;
	cin >> n >> k;
	ll hi = n, lo = 1;
	while(hi >= lo){
		ll mid = (hi + lo)>>1;
		ll total = (mid*(mid+1)) >> 1;
		ll less = (n - mid);
		if(total - less == k){
			cout << less << endl;
			break;
		}
		if(total - less < k){
			lo = mid + 1;
		}
		else
			hi = mid -1;
	}
	return 0;
}