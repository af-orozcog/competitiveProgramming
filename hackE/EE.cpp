/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
	map<int,int> trans;
	int n,e;
	cin >> n >> e;
	int tot = 0;
	vector<vector<int>> nodes(n);
	for(int i = 0; i < e;++i){
		int a,b;
		cin >> a >> b;
		if(trans.count(a) == 0)
			trans[a] = tot++;
		if(trans.count(b) == 0)
			trans[b] = tot++;
		nodes[trans[a]].push_back(b);
		nodes[trans[b]].push_back(a);
	}
	int que;
	cin >> que;
	while(que--){
		int a,b;
		cin >> a >> b;
		bool posi = false;
		for(int i = 0; i < nodes[trans[a]].size();++i){
			if(nodes[trans[a]][i] == b){
				posi = true;
				break;
			}
		}
		if(posi)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}