/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<map>

using namespace std;

map<int,bool> nums;

int main(){
	nums[4] = true;
	nums[8] = true;
	nums[15] = true;
	nums[16] = true;
	nums[23] = true;
	nums[42] = true;
	int vals[4];
	int m = 2;
	for(int i = 0;i < 4;++i){
		cout << "? " << 1 <<" "<< m++<< endl;
		fflush(stdout);
		cin >> vals[i];
	}
	int ans;
	for(auto const &pa: nums){
		bool posi = true;
		for(int i = 0; i < 4;++i){
			if(vals[i] % pa.first != 0 || nums.count(vals[i]/pa.first) == 0){
				posi = false;
				break;
			}
		}
		if(posi){
			ans = pa.first;
			break;
		}
	}
	nums[ans] = false;
	int toGive[] = {ans,-1,-1,-1,-1,-1};
	for(int i = 0; i < 4;++i){
		toGive[i+1] = vals[i]/ans;
		nums[toGive[i+1]] = false;
	}
	for(auto const &pa: nums){
		if(pa.second){
			toGive[5] = pa.first;
			break;
		}
	}
	cout << "! ";
	for(int i = 0; i < 6;++i){
		if(i == 0)
			cout << toGive[i];
		else
			cout << " " << toGive[i];
	}
	cout << endl;
	fflush(stdout);
	return 0;
}