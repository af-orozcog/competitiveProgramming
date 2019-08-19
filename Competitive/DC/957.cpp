/**
* I'm sorry I was an idiot
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int range;
	while(cin >> range){
		int siz;
		cin >> siz;
		vector<int> nums (siz);
		for(int i = 0; i < siz;++i){
			cin >> nums[i];
		}
		int bestN = 0;
		int start;
		int finish;
		for(int i = 0; i < siz; ++i){
			int sta = nums[i];
			int end = sta + range -1;
			vector<int>::iterator up = upper_bound(nums.begin(),nums.end(),end);
			int fin = up - nums.begin();
			if(fin - i > bestN){
				bestN = fin - i;
				start = sta;
				finish = nums[fin-1];
			}
		}
		cout << bestN << " " << start << " " << finish << "\n"; 
	}
	return 0;
}