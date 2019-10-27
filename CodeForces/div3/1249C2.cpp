/**
* I only hope everything will be back to normal
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

int main(){
	int q;
	scanf(" %d",&q);
	vector<ll> check;
	check.push_back(1);
	check.push_back(3);
	ll com = 1000000000000000000;
	ll c = 3;
	while(c <= com){
		c*=3;
		check.push_back(c);
	}
	while(q--){
		ll n; cin >> n;
		vector<bool> used(check.size(),0);
		int first = -1;
		ll co = n;
		for(int i = check.size()-1;i > -1;--i){
			if(check[i] <= n){
				if(first == -1)
					first = i;
				used[i] = 1;
				n -= check[i];
			}
		}
		if(n == 0)
			cout << co << endl;
		else{
			for(int i = 0;i <= first && n > 0;++i){
				if(!used[i])
					n-=check[i];
			}
			if(n < 0)
				cout << co - n << endl;
			else
				cout << check[first+1] << endl;
		}
	}
	return 0;
}