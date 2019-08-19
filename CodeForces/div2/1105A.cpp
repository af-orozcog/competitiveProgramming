/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define HUG 1e+9
#define min(x,y)(x < y?x:y)
#define max(x,y)(x > y?x:y)

using namespace std;

int abs(int x){
	if(x < 0)
		return -x;
	return x;
}

int main(){
	int sti;
	cin >> sti;
	vector<int> nums(sti);
	for(int i = 0; i < sti;++i){
		cin >> nums[i];
	}
	sort(nums.begin(),nums.end());
	int from = nums[0]-1;
	from = max(from,1);
	int to = nums[sti-1]+1;
	int min = HUG;
	int T;
	for(int i = from; i <= to;++i){
		int total = 0;
		for(int j = 0; j < sti;++j){
			if(abs(nums[j]-i)>1)
				total += abs(nums[j]-i)-1;
		}
		if(total < min){
			T = i;
			min = total;
		}
	}
	cout << T << " " << min << endl;
	return 0;
}