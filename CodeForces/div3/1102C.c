/**
* where's the joy?
*/
#include<stdio.h>
#define max(x,y)(x > y? x:y)

int main(){
	int n,x,y;
	scanf(" %d %d %d",&n,&x,&y);
	int nums[n];
	for(int i = 0; i < n;++i){
		scanf(" %d",&nums[i]);
	}
	int turn = 0;
	int open = 0;
	if(x > y){
		printf("%d\n",n);
		return 0;
	}
	while(1){
		int min = 1000000;
		int pos;
		for(int i = 0; i < n; ++i){
			if(nums[i] < min && nums[i] != 0){
				min = nums[i];
				pos = i;
			}
		}
		if(min == 1000000){
			break;
		}
		if(turn){
			nums[pos] += y;
			//if(x >= y)
			--turn;
		}
		else if(turn == 0){
		//	puts("aqui?");
			nums[pos] = max(0,nums[pos]-x);
			if(nums[pos] > 0 && y >= x){
				break;
			}
			else if(nums[pos] == 0)
				++open;
			++turn;
		}
	}
	printf("%d\n",open);
}