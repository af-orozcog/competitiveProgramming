#include<iostream>
#define ll long long

using namespace std;
bool can(){

}

int main(){
	int ve,m;
	while(cin >> ve >> m){
		vector<ll> sums(ve);
		ll total = 0;
		for(int i = 0; i < ve;++i){
			ll val;
			cin >> val;
			total += val;
			sums[i] = total;
		}
		int lo = 0, hi = m - 1;
		while(lo <= hi){
			int mid = (lo+hi) >> 1;

		} 
	}
	return 0;
}