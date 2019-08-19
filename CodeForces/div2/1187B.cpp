/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int siz;
	cin >> siz;
	string imp;
	cin >> imp;
	map<char,vector<int>> indixes;
	for(int i = 0; i < imp.size();++i){
		indixes[imp[i]].push_back(i);
	}
	int que;
	cin >> que;
	while(que--){
		string check;
		cin >> check;
		sort(check.begin(),check.end());
		//cout << check << endl;
		int m = 0;
		char last = check[0];
		int ans = indixes[last][m];
		for(int i = 1; i < check.size();++i){
			if(check[i] == last)
				++m;
			else
				m = 0;
			if(indixes[check[i]][m] > ans)
				ans = indixes[check[i]][m];
			last = check[i];
		}
		cout << ans + 1 << endl;
	}
	return 0;
}