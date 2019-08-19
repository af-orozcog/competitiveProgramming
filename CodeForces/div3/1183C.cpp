/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll long long
#define min(x,y)(x < y? x:y)

using namespace std;

int main(){
	int que;
	cin >> que;
	while(que--){
		ll k,n,a,b;
		cin >> k >> n >> a >> b;
		ll max = 0;
		ll ot = (k/b) - 1;
		if(k - (b*ot) > b)
			++ot;
		if(ot < n){
			cout << -1 << endl;
			continue;
		}
		ll hi = ot;
		ll lo = 0;
		ll coK = k;
		while(hi >= lo){
			ll mid = (hi + lo) >> 1;
			//cout << "mid es: " <<mid <<endl;
			ll oth = b * mid;
			k -= oth;
			ll max1 = (k/a) - 1;
			if(k - (a*max1) > a)
				++max1;
			//cout << max1 << endl;
			k -= a*max1;
			oth = (k/b) - 1;
			if(k - (b*oth) > b)
				++oth;
			oth = min(oth,0);
			if(max1 + mid + oth >= n){
				//cout << max1 <<  " "<< mid <<" " << oth<<endl;
				max = max1;
				hi = mid - 1;
			}
			else
				lo = mid + 1;
			k = coK;
		}
		//cout << now <
		cout << min(max,n) << endl;
	}
	return 0;
}