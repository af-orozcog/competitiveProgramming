/**
* You never know when you'll get a chance
*/
#include<bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	map<int,int> pos;
	int nums[n];
	int from = 0;
	int biggest = 0;
	for(int i = 0; i < n;++i){
		int va;scanf(" %d",&va);
		nums[i] = va;
		pos[va] = 0;
		if(pos.count(va-1))
			pos[va] = pos[va-1]+1;
		if(pos[va] > biggest){
			from = va; biggest = pos[va];
		}
	}
	if(biggest == 0){
		printf("1\n1\n");
		return 0;
	}
	printf("%d\n",biggest+1);
	from -= biggest;
	for(int i = 0,til = biggest+1; til > 0;++i){
		if(nums[i] == from){
			++from;--til;
			printf("%d ",i+1);
		}
	}
	puts("");
	return 0;
}