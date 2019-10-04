#include<iostream>
#include<vector>
#define min(x,y)(x < y? x:y)

using namespace std;

bool isIn(vector<int> &nums,int look){
	int in = -1;
	for(int i = 0; i < nums.size() && in == -1;++i){
		if(nums[i] == look)
			in = i;
	}
	return in == -1;
}


int main(){
	int n,k;
	scanf(" %d %d",&n,&k);
	vector<int> show;
	for(int i = 0; i < n;++i){
		int val;
		scanf(" %d",&val);
		if(isIn(show,val))
			show.insert(show.begin(),val);
		else
			continue;
		if(show.size() > k)
			show.pop_back();
	}
	printf("%d\n",min(k,(int)show.size()));
	for(int i= 0; i < min(k,(int)show.size());++i)
		printf("%d ",show[i]);
	puts("");
	return 0;
}