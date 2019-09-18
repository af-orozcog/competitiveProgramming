#include<stdio.h>
#include<string.h>

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int n;
		scanf(" %d",&n);
		int nums[26];
		memset(nums,0,sizeof(nums));
		for(int i = 0; i < n;++i){
			char re[201];
			short rep[26];
			memset(rep,0,sizeof(rep));
			scanf(" %s",re);
			for(int j = 0; re[j] != '\0';++j)
				rep[re[j]-'a'] = 1;
			for(int j = 0; j < 26;++j)
				nums[j] += rep[j];
		}
		int ans = 0;
		for(int i = 0; i < 26;++i){
			if(nums[i] == n)
				++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}