/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define ll unsigned long long

using namespace std;
vector<unsigned int> possible = {1};
void sett(){
	vector<unsigned int> nums2;
	vector<unsigned int> nums3;
	unsigned int i = 1;
	while(i <= 31){
		nums2.push_back(1 << i);
		++i;
	}
	i = 3;
	unsigned int com = 1 << 31;
	while(i <= (com)){
		nums3.push_back(i);
		i *= 3;
	}
	for(int i = 0; i < nums3.size(); ++i){
		possible.push_back(nums3[i]);
		//cout << "3: " <<nums3[i] << endl;
	}
	for(int i = 0; i < nums2.size();++i){
		possible.push_back(nums2[i]);
		//cout << "2: " << nums2[i] << endl;
	}
	for(int i = 0; i < nums2.size(); ++i){
		for(int j = 0; j < nums3.size();++j){
			if(nums2[i] * nums3[j] <= com)
				possible.push_back(nums2[i] * nums3[j]);
			else 
				break;
		}
	}
}

int main(){
	sett();
	sort(possible.begin(), possible.end());
	unsigned int que;
	while(cin >> que){
		if(que == 0)
			return 0;
		vector<unsigned int>::iterator up = lower_bound(possible.begin(),possible.end(),que);
		cout << possible[up - possible.begin()] << endl;
	}
	return 0;
}