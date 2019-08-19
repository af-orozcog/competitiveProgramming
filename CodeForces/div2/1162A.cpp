#include<iostream>
#include<vector>
#define min(x,y)(x < y?x:y)
#define ll long long

using namespace std;

int main(){
	int n,h,m;
	cin >> n >> h >> m;
	ll ans = 0;
	vector<int> va(n,h);
	for(int i = 0; i < m;++i){
		int l,r;
		ll he;
		cin >> l >> r >> he;
		--l;--r;
		for(int j = l;j <= r;++j)
			va[j] = min(he,va[j]);
	}
	for(int i = 0; i < n;++i){
		ans += va[i]*va[i];
	}
	cout << ans << endl;
	return 0;
}