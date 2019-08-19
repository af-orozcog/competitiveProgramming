/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;
vector<string> nums;
void sett(){
	int com = 1 << 13;
	int i = 0;
	while(i < com){
		int co = i;
		string toPut = "";
		while(co){
			if(co & 1)
				toPut = '2' + toPut;
			else
				toPut = '0' + toPut;
			co = co >> 1;
		}
		int b =  toPut.size();
		for(int i = 0; i < 13 - b;++i){
			toPut = '0' + toPut;
		}
		nums.push_back(toPut);
		++i;
	}
}
double value(string check){
	double ans = 0;
	double three = 1;
	for(int i = 0; i < check.size();++i){
		three /= 3;
		if(check[i] != '0')
			ans += 2 * three;
	}
	return ans;
}

int main(){
	sett();
	string toSee;
	//sort(nums.begin(),nums.end());
	/*for(int i = 0; i < 10; ++i){
		cout << nums[i] << endl;
	}*/
	while(true){
		cin >> toSee;
		if(toSee.compare("END") == 0)
			return 0;
		double check = stod(toSee);
		int lo = 0, hi = nums.size() - 1;
		double com = 0.000001;
		bool posi = false;
		while(lo <= hi){
			int mid = (lo+hi) >> 1;
			if(abs(value(nums[mid])- check) <= com){
				posi = true;
				break;
			}
			else if(value(nums[mid]) > check)
				hi = mid - 1;
			else
				lo = mid + 1;
			//cout << mid << endl
		}
		if(posi)
			cout << "MEMBER" << endl;
		else
			cout << "NON-MEMBER" << endl;
	}
	return 0;
}