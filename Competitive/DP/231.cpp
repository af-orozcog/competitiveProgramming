/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#define max(x,y)(x > y ? x: y)

using namespace std;

int solve(vector<int> &nums){
	int memo[nums.size()];
	memo[0] = 1;
	int valmax = 1;
	for(int i = 1;i < nums.size();++i){
		int ans = 1;
		for(int j = i - 1; j >= 0;--j){
			if(nums[j] >= nums[i])
				ans = max(ans,memo[j] +1);
		}
		memo[i] = ans;
		valmax = max(valmax,ans);
	}
	return valmax;
}

int main(){
	bool fir = true;
	vector<int> numbers;
	int tes = 1;
	bool first = true;
	while(true){
		int val;
		cin >> val;
		if(val == -1 && first)
			break;
		if(val == -1){
			if(!fir)
				cout << endl;
			first = true;
			cout << "Test #" << tes << ":"<< endl;
			cout << "  maximum possible interceptions: " <<solve(numbers) << endl;
			numbers.clear();
			fir = false;
			++tes;
			continue;
		}
		first = false;
		numbers.push_back(val);
	}
	return 0;
}