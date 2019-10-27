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
	int n;
	scanf(" %d",&n);
	int nums[n];
	for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
	vector<int> dp(n,0);
	int ans = 0;
	for(int i = n-1;i >=0;--i){
		int next = (nums[i]<<1);
		int index = lower_bound(nums,nums+n,next)-nums;
		//cout << index << endl;
		if(index != n || (index == n && index-1 != i)){
		    if(index == n) --index;
			if(nums[index] > (nums[i]<<1))
				--index;
			dp[i] += (index-i);
			if(index != i)
				dp[i] += dp[index];
		}
		//cout << "dp is " << dp[i] << endl;
		ans = max(ans,dp[i]);
	}
	printf("%d\n",ans+1);
	return 0;
}