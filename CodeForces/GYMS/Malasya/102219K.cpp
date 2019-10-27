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
	int t;
	scanf(" %d",&t);
	for(int k = 1; k <= t;++k){
		int n;
		scanf(" %d",&n);
		ll nums[n];
		for(int i = 0; i < n;++i) cin >> nums[i];
		sort(nums,nums+n);
		ll cm = 0;
		int ans = 0;
		for(int i = 0; i < n;++i){
			if(cm < nums[i]){
				++ans;
				cm += nums[i];
			}
		}
		cout <<"Case # " << k<<": " <<ans << endl;
	}
	return 0;
}