/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	int N,L;
	cin >> N >> L;
	vector<int> nums(N);
	int tot = 0;
	for(int i = 0; i < N; ++i){
		int val = L + i;
		nums[i] = val;
		tot += val;
	}
	int best = abs(nums[0]);
	int ind = 0;
	for(int i = 1; i < N;++i){
		if(abs(nums[i]) < best){
			best = abs(nums[i]);
			ind = i;
		}
	}
	cout << tot - nums[ind] << endl;
	return 0;
}