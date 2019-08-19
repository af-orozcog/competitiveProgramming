/**
* I'm sorry I was an idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int main(){
	int siz;
	cin >> siz;
	vector<int> nums(siz);
	vector<int> odd;
	vector<int> even;
	for(int i = 0; i < siz;++i){
		cin >> nums[i];
		if(nums[i] % 2 == 0)
			even.push_back(nums[i]);
		else
			odd.push_back(nums[i]);
	}
	if(odd.size() == 0 || even.size() == 0){
		for(int i = 0; i < nums.size(); i++){
			if(i != nums.size() - 1)
				cout << nums[i] << " ";
			else
				cout << nums[i] << "\n";
		}
		return 0;
	}
	int eve = 0;
	int od = 0;
	sort(even.begin(),even.end());
	sort(odd.begin(),odd.end());
	int i = 0;
	for(;i < siz;++i){
		if(od == odd.size() || eve == even.size())
			break;
		if(min(even[eve],odd[od]) == odd[od])
			nums[i] = odd[od++];
		else
			nums[i] = even[eve++];
	}
	if(eve == even.size()){
		for(;i < siz; ++i){
			nums[i] = odd[od++];
		}
	}
	else{
		for(; i < siz;++i){
			nums[i] = even[eve++];
		}
	}
	for(int i = 0; i < nums.size(); i++){
			if(i != nums.size() - 1)
				cout << nums[i] << " ";
			else
				cout << nums[i] << "\n";
	}
	return 0;
}