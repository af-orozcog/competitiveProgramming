#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long

using namespace std;

int main(){
	ll n,m;
	cin >> n >> m;
	vector<ll> he(n);
	for(int i = 0; i < n;++i){
		cin >> he[i];
	}
	sort(he.begin(),he.end());
	ll ans = 0;
	for(int i = 0; i < n-1;++i){
		ans += he[i]-1;
	}
	cout << ans << endl;
}