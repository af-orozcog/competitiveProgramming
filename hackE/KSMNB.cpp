#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long


using namespace std;
typedef vector<pair<ll,ll>> vi;

int main(){
	int t;
	scanf(" %d",&t);
	vector<ll> smallest;
	while(t--){
		int n,q;
		scanf(" %d %d",&n,&q);
		vi ran;
		for(int i = 0; i < n;++i){
			ll a,b;
			scanf(" %lld %lld",&a,&b);
			ran.push_back({a,b});
		}
	}
}