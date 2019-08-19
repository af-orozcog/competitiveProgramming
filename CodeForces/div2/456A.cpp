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
	int siz;
	cin >> siz;
	vector<pair<int,int>> n(siz);
	for(int i = 0; i < siz;++i){
		int a,b;
		cin >> a >> b;
		n[i] = make_pair(a,b);
	}
	sort(n.begin(),n.end(),com);
	for(int i = 0; i < siz-1;++i){
		if(n[i].first < n[i+1].first && n[i].second > n[i+1].second){
			cout << "Happy Alex\n";
			return 0;
		}
	}
	puts("Poor Alex");
	return 0;
}