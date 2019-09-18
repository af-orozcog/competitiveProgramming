#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	int n,d;
	scanf(" %d %d",&n,&d);
	int nums[n];
	for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
	sort(nums,nums+n);
	int i = 0;
	int ans =0;
	while(i < n-1){
		if(nums[i+1]-nums[i] <= d){
			++ans;
			i += 2;
		}
		else
			++i;
	}
	printf("%d\n",ans);
	return 0;
}