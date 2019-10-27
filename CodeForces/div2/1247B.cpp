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
	while(t--){
		int n,k,d;
		scanf(" %d %d %d",&n,&k,&d);
		int nums[n];
		for(int i = 0; i < n;++i)scanf(" %d",&nums[i]);
		map<int,int> check;
		for(int i = 0;i < d;++i){
			if(check.count(nums[i]))
				++check[nums[i]];
			else
				check[nums[i]] = 1;
		}
		ll ans = (ll)check.size();
		for(int i = 1, j = d; j < n;++i,++j){
			--check[nums[i-1]];
			if(check[nums[i-1]] == 0)
				check.erase(nums[i-1]);
			if(check.count(nums[j]))
				++check[nums[j]];
			else
				check[nums[j]] = 1;
			ans = min(ans,(ll)check.size());
		}
		cout << ans << endl;
	}
	return 0;
}