/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
#define ll long long
using namespace std;
bitset<1000001> possible;
vector<int> nums;
void initia(){
	possible.set();
	for(int i = 2; i <= 1000000;++i){
		if(possible[i]){
			int m = 2;
			while(i * m <= 1000000){
				possible.set(i*m,0);
				++m;
			}
			nums.push_back(i);
		}
	}
}

int main(){
	initia();
	int counter = 1;
	while(true){
		int val;
		cin >> val;
		if(val == 0)
			return 0;
		vector<int>::iterator low = lower_bound(nums.begin(),nums.end(),val);
		int up = low - nums.begin();
		if(low == nums.end())
			up--;
		/*if(val >= nums[nums.size()-1] + nums[nums.size()-2]){
			ll ans = (nums.size()*(nums.size()-1)) >> 1;
			cout << "Case " <<counter++ << ": " << ans << endl;
			continue;
		}*/
		ll taken = 0;
		int down = 0;
		ll total = 0;
		//cout << "up es: " << up << endl;
		while(down <= up){
			if(down == up){
				total += taken;
				break;
			}
			else if(nums[up] + nums[down] > val){
				--up;
				total += taken;
				continue;
			}
			else{
				++taken;
				++down;
			}
		}
		total += (down*(down-1)) >> 1;
		cout << "Case " <<counter++ << ": " <<total << endl;
	}
}