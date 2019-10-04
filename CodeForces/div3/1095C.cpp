#include<iostream>
#include<queue>

using namespace std;

int main(){
	int n,k;
	scanf(" %d %d",&n,&k);
	int ones = 0;
	if(n&1){
		++ones;
		n--;
	}
	priority_queue<int> nums;
	while(n){
		int dig = n &(-n);
		nums.push(dig);
		n-=dig;
	}
	while(ones + (int)nums.size() < k && nums.size()){
		int f = nums.top();nums.pop();
		f = (f>>1);
		if(f == 1)
			ones += 2;
		else{
			nums.push(f);nums.push(f);
		}
	}
	if(ones+(int)nums.size() == k){
		puts("YES");
		for(int i = 0; i < ones;++i)
			printf("%d ",1);
		while(nums.size()){
			printf("%d ",nums.top());
			nums.pop();
		}
		puts("");
	}
	else
		puts("NO");
}