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
	while(1){
		int n,t;
		scanf(" %d",&t);
		if(!t)
			break;
		scanf(" %d",&n);
		int nums[n];
		for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
		vector<vector<int>> dp(2, vector<int>(t+1));
		for(int i = 0; i < t+1;++i)
		    dp[0][i] = dp[1][i] = -1;
		dp[0][0] = 1000000000;
		int maxi = 0;
		for(int j = 0; j < n;++j){
			for(int i = 0; i <= t;++i){
				if(i - nums[j] >= 0 && dp[0][i-nums[j]] != -1){
					if(dp[0][i] == -1)
						dp[1][i] = j;
					else{
						vector<int> pos1;
						vector<int> pos2;
						int co = i-nums[dp[0][i]];
						while(dp[0][co] != 1000000000){
							pos1.push_back(nums[dp[0][co]]);
							co -= nums[dp[0][co]];
						}
						co = i - nums[j];
						while(dp[0][co] != 1000000000){
							pos2.push_back(nums[dp[0][co]]);
							co -= nums[dp[0][co]];
						}
						bool fi = 1;
						for(int k = 0; k < min(pos1.size(),pos2.size()) && fi;++k){
							if(pos2[k] < pos1[k])
								fi = 0;

						}
						if(!fi)
							dp[1][i] = j;
					}
					maxi = max(maxi,i);
				}
			}
			dp[0] = dp[1];
		//	for(int i = 0; i < dp[1].size();++i)
		//		dp[1][i] = -1;
			dp[0][0] = 1000000000;
		}
		int co = maxi;
		vector<int> ans;
		while(dp[0][maxi] != 1000000000){
			ans.push_back(nums[dp[0][maxi]]);
			maxi -= nums[dp[0][maxi]];
		}
		for(int i = ans.size()-1; i > -1;--i)
			cout << ans[i] <<" ";
		cout << co << endl;
	}	
	return 0;
}