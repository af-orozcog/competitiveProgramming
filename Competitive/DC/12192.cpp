#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	while(true){
		int x,y;
		cin >> x >> y;
		if(x == 0)
			return 0;
		vector<vector<int>> nums(x);
		for(int i = 0; i < x;++i){
			for(int j = 0; j < y;++j){
				int val;
				cin >> val;
				nums[i].push_back(val);
			}
		}
		int que;
		cin >> que;
		while(que--){
			int down,up;
			cin >> down >> up;
			int max = 0;
			vector<int>::iterator low;
			for(int i = 0; i < x;++i){
				low = lower_bound(nums[i].begin(),nums[i].end(),down);
				if(low != nums[i].end()){
					int siz = 1;
					int m = low - nums[i].begin();
					if(nums[i][m] > up)
						continue;
					++m;
					for(int j = i + 1; j < x && m < y; ++j){
						if(nums[j][m] > up)
							break;
						++m;
						++siz;
					}
					if(siz > max)
						max = siz;
				}
			}
			cout << max << endl;
		}
		cout << "-" << endl;
	}
	return 0;
}