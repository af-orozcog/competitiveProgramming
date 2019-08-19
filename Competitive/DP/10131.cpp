/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

bool com(const pair<int,pair<int,int>> a,const pair<int,pair<int,int>> b){
	return a.first < b.first;
}
bool com2(const int a, const int b){
	return a > b;
}

void createBack(vector<pair<int,pair<int,int>>> &a,vector<int> &P,int last){
	int x = last;
	stack<int> ans;
	for(; P[x] >= 0;x = P[x]) ans.push(a[x].second.second);
	printf("%d\n",a[x].second.second);
	while(ans.size()){
		printf("%d\n",ans.top());
		ans.pop();
	}
}

int main(){
	vector<pair<int,pair<int,int>>> ele;
	int siz,iq;
	int n = 1;
	while(cin >> siz >> iq){
		ele.push_back(make_pair(siz,make_pair(iq,n)));
		++n;
	}
	sort(ele.begin(),ele.end(),com);
	vector<int> LIS(ele.size());
	vector<int> lis_id(ele.size());
	vector<int> P(ele.size());
	int added = 0, last = 0;
	for(int i = 0; i < ele.size();++i){
		vector<int>::iterator low = lower_bound(LIS.begin(),LIS.begin() + added,ele[i].second.first,com2);
		int index = low - LIS.begin();
		if(index != 0){
			if(ele[lis_id[index-1]].first == ele[i].first)
				continue;
		}
		LIS[index] = ele[i].second.first;
		lis_id[index] = i;
		P[i] = index ? lis_id[index-1]:-1;
		if(index == added){
			++added;
			last = i;	
		}
	}
	printf("%d\n",added);
	createBack(ele,P,last);
	return 0;
}