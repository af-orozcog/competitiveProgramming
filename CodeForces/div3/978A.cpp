#include<iostream>
#include<stack>
#include<set>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	int nums[n];
	for(int i = 0; i < n;++i)scanf(" %d",&nums[i]);
	set<int> uni;
	stack<int> ans;
	for(int i = n-1;i >= 0;--i){
		if(uni.count(nums[i]) == 0){
			uni.insert(nums[i]);
			ans.push(nums[i]);
		}
	}
	printf("%d\n",(int)ans.size());
	while(ans.size()){
		printf("%d ",ans.top());
		ans.pop();
	}
	puts("");
	return 0;
}