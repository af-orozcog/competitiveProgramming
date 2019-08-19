/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

void createBack(vector<int> &a,vector<int> &P,int last){
	int x = last;
	stack<int> ans;
	for(;P[x] >= 0;x = P[x]) ans.push(a[x]);
	printf("%d\n",a[x]);
	while(ans.size()){
		printf("%d\n",ans.top());
		ans.pop();
	}
}

int main(){
	int cas;
	cin >> cas;
	cin.ignore();
	string lel;
	getline(cin,lel);
	while(cas--){
		vector<int> nums;
		string num;
		while(true){
			getline(cin,num);
			if(num.size() == 0)
				break;
			nums.push_back(stoi(num));
		}
		vector<int> LIS(nums.size(),-1);
		vector<int> id_lis(nums.size());
		vector<int> P(nums.size());
		int last = 0,added = 0;
		for(int i = 0; i < nums.size();++i){
			vector<int>::iterator low = lower_bound(LIS.begin(),LIS.begin()+added,nums[i]);
			int index = low - LIS.begin();
			id_lis[index] = i;
			LIS[index] = nums[i];
			P[i] = index ? id_lis[index-1]:-1;
			if(index == added){
				++added;
				last = i;
			}
		}
		printf("Max hits: %d\n",added);
		createBack(nums,P,last);
		if(cas != 0)
			printf("\n");
	}
}