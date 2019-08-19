/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool com(const pair<int,int> a,const pair<int,int> b){
	if(a.first < b.first)
		return true;
	if(a.first > b.first)
		return false;
	return a.second < b.second;
}

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int many;
		cin >> many;
		vector<pair<int,int>> mat(many);
		for(int i = 0; i < many;++i){
			int a,b;
			cin >> a >> b;
			mat[i] = make_pair(a,b);
		}
		sort(mat.begin(),mat.end(),com);
		vector<int> LIS(many);
		vector<int> id_lis(many);
		int added = 0;
		for(int i = 0;i < many;++i){
			int index = lower_bound(LIS.begin(),LIS.begin()+added,mat[i].second) - LIS.begin();
			if(index != 0 && mat[id_lis[index-1]].first == mat[i].first)
				continue;
			LIS[index] = mat[i].second;
			id_lis[index] = i;
			if(index == added)
				++added;
		}
		cout << (many - added) + 1<< endl;
	}
}