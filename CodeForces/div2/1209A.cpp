#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	int nums[n];
	for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
	sort(nums,nums+n);
	bool co[n];
	memset(co,false,sizeof(co));
	int ans = 0;
	for(int i = 0; i < n;++i){
		if(!co[i]){
			for(int j = i+1; j < n;++j){
				if(nums[j] % nums[i] == 0)
					co[j] = true;
			}
			++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}