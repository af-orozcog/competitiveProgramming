/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool com(const pair<int,int> a, const pair<int,int> b){
	if(a.first < b.first)
		return true;
	if(a.first > b.first)
		return false;
	return a.second > b.second;
}

int main(){
	int s,siz;
	cin >> s >> siz;
	vector<pair<int,int>> nums(siz);
	for(int i = 0; i < siz;++i){
		int val1,val2;
		cin >> val1 >> val2;
		nums[i] = make_pair(val1,val2);
	}
	sort(nums.begin(),nums.end(),com);
	for(int i = 0; i < siz;++i){
		if(s <= nums[i].first){
			puts("NO");
			return 0;
		}
		s += nums[i].second;
	}
	puts("YES");
	return 0;
}