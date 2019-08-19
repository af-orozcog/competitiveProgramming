/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	vector<int> nums = {a,b,c,d};
	if(nums[0] + nums[1] > nums[2] && nums[0] + nums[2] > nums[1]
		&& nums[1] + nums[2] > nums[0]){
		cout << "TRIANGLE" << endl;
		return 0; 
	}
	if(nums[0] + nums[2] > nums[3] && nums[0] + nums[3] > nums[2]
		&& nums[2] + nums[3] > nums[0]){
		cout << "TRIANGLE" << endl;
		return 0; 
	}
	if(nums[0] + nums[1] > nums[3] && nums[0] + nums[3] > nums[1]
		&& nums[1] + nums[3] > nums[0]){
		cout << "TRIANGLE" << endl;
		return 0;
	}
	if(nums[1] + nums[2] > nums[3] && nums[1] + nums[3] > nums[2]
		&& nums[2] +nums[3] > nums[1]){
		cout << "TRIANGLE" << endl;
		return 0;
	}
	if(nums[0] + nums[1] == nums[3] || nums[0] + nums[3] == nums[1]
		|| nums[1] + nums[3] == nums[0]){
		cout << "SEGMENT" << endl;
		return 0;
	}
	if(nums[0] + nums[2] == nums[3] || nums[0] + nums[3] == nums[2]
		|| nums[2] + nums[3] == nums[0]){
		cout << "SEGMENT" << endl;
		return 0;
	}
	if(nums[1] + nums[2] == nums[3] || nums[1] + nums[3] == nums[2]
		|| nums[2] +nums[3] == nums[1]){
		cout << "SEGMENT" << endl;
		return 0;
	}
	if(nums[0] + nums[1] == nums[2] || nums[0] + nums[2] == nums[1]
		|| nums[1] + nums[2] == nums[0]){
		cout << "SEGMENT" << endl;
		return 0;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}