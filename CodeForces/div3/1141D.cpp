#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int main(){
	vector<queue<int>> vals1(27);
	vector<queue<int>> vals2(27);
	vector<pair<int,int>> ans;
	int siz;
	cin >> siz;
	string first;
	string second;
	cin >> first;
	cin >> second;
	for(int i = 0; i < siz;++i){
		if(first[i] == '?'){
			vals1[26].push(i);
		}
		else
			vals1[first[i]-'a'].push(i);
	}
	for(int i = 0; i < siz;++i){
		if(second[i] == '?'){
			vals2[26].push(i);
//			cout << "netro" << endl;
		}
		else{
			if(vals1[second[i] - 'a'].size()){
				ans.push_back(make_pair(vals1[second[i]-'a'].front()+1,i+1));
				vals1[second[i]-'a'].pop();
			}
			else
				vals2[second[i]-'a'].push(i);
		}
	}
	
	for(int i = 0; i < vals1.size()-1;++i){
		while(vals1[i].size() && vals2[26].size()){
			ans.push_back(make_pair(vals1[i].front()+1,vals2[26].front()+1));
			vals1[i].pop();
			vals2[26].pop();
		}
	}
	for(int i = 0; i < vals2.size()-1;++i){
		while(vals2[i].size() && vals1[26].size()){
			ans.push_back(make_pair(vals1[26].front()+1,vals2[i].front()+1));
			vals2[i].pop();
			vals1[26].pop();
		}
	}
	while(vals1[26].size() && vals2[26].size()){
		ans.push_back(make_pair(vals1[26].front()+1,vals2[26].front()+1));
		vals2[26].pop();
		vals1[26].pop();
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size();++i){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}