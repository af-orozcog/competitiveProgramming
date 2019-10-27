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
		int one= -20;
		int n;
		scanf(" %d",&n);
		int nums[n];
		for(int i = 0; i < n;++i)scanf(" %d",&nums[i]);
		sort(nums,nums+n);
		bool pos = 0;
		for(int i = 0; i < n && !pos;++i){
			if(abs(nums[i]-one)!= 1)
				one = nums[i];
			else 
				pos= 1;
		}
		if(pos)
			puts("2");
		else
			puts("1");
	}
	return 0;
}