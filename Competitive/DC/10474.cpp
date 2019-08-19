/**
* I'm sorry I was an idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int cas = 1;
	while(true){
		int siz,que;
		cin >> siz >> que;
		if(siz == que && siz == 0)
			break;
		vector<int> nums(siz);
		cout << "CASE# " << cas <<":" << endl;
		for(int i = 0; i < siz; ++i){
			cin >> nums[i];
		}
		sort(nums.begin(),nums.end());
		while(que--){
			int val;
			cin >> val;
			vector<int>::iterator low = lower_bound(nums.begin(),nums.end(),val);
			if(low == nums.end() || nums[low - nums.begin()] != val)
				cout << val << " not found\n";
			else
				cout << val << " found at " << low - nums.begin() + 1 << endl;
		}
		++cas;
	} 
	return 0;
}