#include<bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	int nums[n];
	for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
	int LIS[n],LIS_id[n],memo[n];
	int siz=0,last=-1;
	for(int i = 0; i < n;++i){
		int index = lower_bound(LIS,LIS+siz,nums[i])-LIS;
		LIS[index] = nums[i];
		LIS_id[index] = i;
		memo[i] = index ? LIS_id[index-1]:-1;
		if(index == siz){
			++siz;
			last = i;
		}
	}
	printf("%d\n",siz);
	stack<int> ans;
	ans.push(nums[last]);
	for(int x = memo[last];x!= -1;x=memo[x]) ans.push(nums[x]);
	while(ans.size()){
		printf("%d ",ans.top()); ans.pop();
	}
	puts("");
	return 0;
}