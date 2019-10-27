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
	while(q--){
		int n;
		scanf(" %d",&n);
		int nums[n];
		for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
		int show[n];
		for(int i = 0; i < n;++i){
			int ans = 1;
			int co = i;
			while(nums[co]-1 != i){
				co = nums[co]-1;
				++ans;
			}
			show[i] = ans;
		}
		for(int i = 0; i < n;++i)
			printf("%d ",show[i]);
		puts("");
	}
	return 0;
}