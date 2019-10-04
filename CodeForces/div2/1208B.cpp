#include<iostream>
#include<set>
#define max(x,y)(x > y? x:y)
#define min(x,y)(x < y? x:y)

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	int nums[n];
	for(int i = 0; i < n;++i)scanf(" %d",&nums[i]);
	//for(int i = 0; i < n;++i)printf("%d ",nums[i]);
	int ans = 100000000;
	for(int i = 0; i <= n;++i){
		set<int> imp;
		int j = 0;
		for(; j < i;++j){
			if(imp.count(nums[j])){
				--j;
				break;
			}
			imp.insert(nums[j]);
		}
		int k = n-1;
		int less = n;
		for(;k > j && k >=i;--k){
		   // printf("%d\n",nums[k]);
			if(imp.count(nums[k]))
				break;
			imp.insert(nums[k]);
			--less;
		}
		
		ans = min(ans,less-j);
	}
	printf("%d\n",ans);
	return 0;
}