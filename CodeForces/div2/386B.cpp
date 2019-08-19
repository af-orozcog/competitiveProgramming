#include<iostream>
#include<vector>
#include<algorithm>
#define max(x,y)(x >y?x:y)

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	vector<int> nums(n);
	for(int i = 0; i < n;++i)
		scanf(" %d",&nums[i]);
	int k;
	scanf(" %d",&k);
	sort(nums.begin(),nums.end());
	int ans = 1;
	for(int i = 0;i < n;++i){
		int val;
		int j = i+1;
		for(; j < n;++j){
			if(nums[j] - nums[i] > k)
				break;
		}
		ans = max(ans,j - i);
	}
	printf("%d\n",ans);
	return 0;
}