/**
* I only hope everything will be back to normal
*/
#include<iostream>
#include<vector>
#include<cstring>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

int main(){
	int n;
	cin>>n;
	ll dp = 0;
	vector<int> who;
	ll cm = 0;
	ll count = 0;
	vector<int> out(n+1,0);
	for(int i = 1; i <= n;++i){
		cm -= count;
		count -= out[i];
		//cout << cm << endl;
		ll v,d,p;cin>>v>>d>>p;
		if(p -(cm + dp) >= 0){
			who.push_back(i);
			cm += (v+1);
			++count;
			if(i+v+1 <= n)
				++out[i+v+1];
		}
		else
			dp += d;
	}
	cout << who.size() << endl;
	for(auto &va:who)
		printf("%d ",va);
	puts("");
	return 0;
}