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
	for(int i = 1; i <= t;++i){
		int n,s;
		scanf(" %d %d",&n,&s);
		int nums[n];
		for(int j = 0; j < n;++j){
			int a,b;
			scanf(" %d %d",&a,&b);
			if(s < b)
				nums[j] = a - (b-s);
			else
				nums[j] = a;
		}
		sort(nums,nums+n);
		printf("Case #%d: %d\n",i,nums[n-1]);
	}
	return 0;
}