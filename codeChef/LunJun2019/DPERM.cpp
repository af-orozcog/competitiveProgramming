#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define abs(x)(x < 0? -x:x)
#define ll long long

using namespace std;

void swap(vector<int> &vec,int a,int b){
	int temp = vec[a];
	vec[a] = vec[b];
	vec[b] = temp;
}

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		map<int,int> index;
		int siz,ab;
		cin >> siz >> ab;
		vector<int> nums(siz);
		for(int i = 0; i < siz; ++i){
			cin >> nums[i];
			index[nums[i]] = i;
		}
		vector<int> copy = nums;
		sort(copy.begin(),copy.end());
		ll total = 0;
		bool posi = true;
		for(int i = 0; i < siz;++i){
			if(copy[i] != nums[i]){
				if(abs(copy[i]-nums[i]) == ab){
					index[nums[i]] = index[copy[i]];
					swap(nums,i,index[copy[i]]);
					index[copy[i]] = -1;
					++total;
				}
			}
		}
	}
}