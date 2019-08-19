#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int n,m,k;
		scanf(" %d %d %d",&n,&m,&k);
		vector<int> nums(n);
		for(int i = 0; i < n;++i)
			scanf(" %d",&nums[i]);
		bool posi = true;
		for(int i = 0; i < n -1 && posi;++i){
			if(abs(nums[i] - nums[i+1]) <= k){
				int val = max(0,-k+nums[i+1]);
				m += (nums[i] - val);
			}
			if(abs(nums[i] - nums[i+1]) > k){
				if(nums[i] < nums[i+1]){
					int val = -k+nums[i+1];
					if(m - (val-nums[i]) < 0)
						posi = false;
					else
						m -= (val-nums[i]);
				}
				else{
					int val = max(0,-k+nums[i+1]);
					m += (nums[i] - val);
				}
			}
		}
		if(posi)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}