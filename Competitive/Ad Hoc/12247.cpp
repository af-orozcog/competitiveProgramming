#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int prin[3],pi[2];
	while(scanf(" %d %d %d %d %d",&prin[0],&prin[1],&prin[2],&pi[0],&pi[1]) && prin[0]){
		sort(prin,prin+3);
		short po = 0;
		for(int i = 1; i<=52;++i){
			if(i == prin[0] || i == prin[1] || i == prin[2]
				|| i == pi[0] || i == pi[1])
				continue;
			int nums[3] = {pi[0],pi[1],i};
			sort(nums,nums+3);
			if(nums[2] < prin[1] || nums[1] < prin[1]) continue;
			if(nums[2] > prin[2] && nums[1] < prin[1]) continue;
		}
		if(!po)
			puts("-1");
	}
	return 0;
}