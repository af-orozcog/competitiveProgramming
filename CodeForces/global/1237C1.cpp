/**
* ALL I DO IS WRONG
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

int main(){
	int n;
	scanf(" %d",&n);
	map<pair<int,int>,priority_queue<int>> three;
	map<pair<int,pair<int,int>>,int> pos;
	for(int i = 0; i < n;++i){
		int x,y,z;
		scanf(" %d %d %d",&x,&y,&z);
		three[{x,y}].push(z);
		pos[{x,{y,z}}] = i;
	}
	vector<int> ans;
	map<int,priority_queue<pair<int,int>>> byX;
	for(auto &va: three){
		priority_queue<int> &check = va.second; 
		int siz = (int)check.size();
		while(siz > 1){
			ans.push_back(pos[{va.first.first,{va.first.second,check.top()}}]);
			check.pop();
			ans.push_back(pos[{va.first.first,{va.first.second,check.top()}}]);
			check.pop();
			siz -= 2;
		}
		if(siz){
			byX[va.first.first].push({va.first.second,check.top()});
			check.pop();
		}
	}
	//cout << "here the size is: " << ans.size()<<endl;
	vector<pair<int,pair<int,int>>> nums;
	for(auto &va:byX){
		priority_queue<pair<int,int>> &check = va.second;
		int siz = (int)check.size();
		while(siz > 1){
			ans.push_back(pos[{va.first,{check.top().first,check.top().second}}]);
			check.pop();
			ans.push_back(pos[{va.first,{check.top().first,check.top().second}}]);
			check.pop();
			siz -= 2;
		}
		if(siz){
			nums.push_back({va.first,{check.top().first,check.top().second}});
			check.pop();
		}
	}
	//cout << "nums size is " <<nums.size() <<endl;
	sort(nums.begin(),nums.end());
	for(int i = 0; i < nums.size();i+=2){
		ans.push_back(pos[nums[i]]);
		ans.push_back(pos[nums[i+1]]);
	}
	for(int i = 0; i < ans.size();i+=2)
		printf("%d %d\n",ans[i]+1,ans[i+1]+1);
	return 0;
}