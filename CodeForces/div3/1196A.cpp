#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define min(x,y)(x < y? x:y)

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		vector<ll> a(3);
		cin >> a[0] >> a[1] >> a[2];
		sort(a.begin(),a.end());
		ll bo = a[0];
		ll al = a[1];
		ll sum = bo - (al+a[2]);
		sum = -sum;
		//cout << "here sum " << sum << endl;
		sum = sum >> 1;
		//cout << "sum es " << sum << endl;
		cout << min(bo + sum, al +(a[2]-sum)) << endl;
	}
	return 0;
}