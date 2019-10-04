#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int a,b,c,d;
	scanf(" %d %d %d %d",&a,&b,&c,&d);
	int sum = a+b+c+d;
	if(sum & 1){
		puts("NO");return 0;
	}
	int nums[] = {a,b,c,d};
	sort(nums,nums+4);
	if((sum>>1) - nums[3] == 0){
		puts("YES");return 0;
	}
	int index = lower_bound(nums,nums+4,(sum>>1)-nums[3]) -nums;
	if(index < 4 && nums[index] + nums[3] == (sum>>1)){
		puts("YES");return 0;
	}
	puts("NO");
	return 0;
}