#include<iostream>
#include<algorithm>
#include<deque>
#include<stack>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	int nums[n];
	for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
	sort(nums,nums+n);
	for(int i = 1;i < n;++i){
		for(int j = i-1; j >= 0;--j){
			if(nums[j] < nums[i] && nums[j] != 0){
				nums[j] = 0;
				break;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n;++i)
		ans += nums[i];
	printf("%d\n",ans);
	return 0;
}