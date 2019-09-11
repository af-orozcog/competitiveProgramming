/**
* I do this because of Valentina 
*/
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	int nums[n];
	for(int i = 0; i <n;++i)scanf(" %d",&nums[i]);
	sort(nums,nums+n);
	int j = 0; 
	for(int i = 1; i < 3002;++i){
		if(nums[j] != i){
			printf("%d\n",i);
			return 0;
		}
		if(j == n)
			break;
		++j;
	}
	printf("%d\n", 3001);
	return 0;
}