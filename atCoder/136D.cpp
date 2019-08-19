#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){
	string re;
	cin >> re;
	int nums[re.size()];
	int changed[re.size()];
	memset(nums,0,sizeof(nums));
	memset(changed,0,sizeof(changed));
	for(int i = 0; i < re.size();++i){
		if(re[i] == 'R'){
			++nums[i+1];
			--nums[i];
		}
		else{
			++nums[i-1];
			--nums[i];
		}
	}
	int c = 1;
	while(c){
		int c = 0;
		for(int i = 0; i < re.size();++i){
			if(re[i] == 'R'){
				++nums[i+1];
				--nums[i];
				++changed[i+1];
				--changed[i];
				if(changed[i+1] || changed[i])
					c = 1;
				else
					c = 0;
			}
			else{
				++nums[i-1];
				--nums[i];
				++changed[i-1];
				--changed[i];
				if(changed[i-1] || changed[i])
					c = 1;
				else
					c = 0;
			}
		}
	}
	for(int i = 0; i < re.size();++i){
		if(i == 0)
			printf("%d", nums[i]);
		else
			printf(" %d",nums[i]);
	}
	puts("");
}