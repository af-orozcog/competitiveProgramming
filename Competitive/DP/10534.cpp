/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define max(x,y)(x > y? x:y)
#define min(x,y)(x < y ? x:y)

using namespace std;
void longest(vector<int> &a,vector<int> &b){
	vector<int> LIS(a.size());
	int added = 0;
	for(int i = 0; i < a.size();++i){
		int index = lower_bound(LIS.begin(),LIS.begin()+added,a[i]) - LIS.begin();
		LIS[index] = a[i];
		if(index == added)
			++added;
		b[i] = index + 1;  
	}
}

int main(){
	int siz;
	while(cin >> siz){
		vector<int> nums(siz);
		//cout << "aqui??" << endl;
		for(int i = 0;i < siz;++i){
			//cout << "what" << endl;
			cin >> nums[i];
		}
		vector<int> LIS(siz);
		int addedI = 0;
		int ans = 1;
		vector<int> ascending(nums.size());
		vector<int> descending(nums.size());
		longest(nums,ascending);
		reverse(nums.begin(),nums.end());
		longest(nums,descending);
		for(int i = 0; i < nums.size();++i){
			int pos = min(ascending[i],descending[nums.size()-1-i]);
			ans = max(ans,pos*2 - 1);
		}
		printf("%d\n",ans);
	}
	return 0;
}