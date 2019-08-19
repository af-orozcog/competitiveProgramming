/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<map>
#include<vector>

using namespace std;
int total = 0;
map<int,int> trans;
vector<bool> marked;
void dfs(vector<vector<int>> nodes, int start){
	++total;
	marked[start] = true;
	for(int i = 0; i < nodes[start].size();++i){
		if(!marked[nodes[start][i]]){
			dfs(nodes,nodes[start][i]);
		}
	}
}

int main(){
	int t = 0;
	int no,ed;
	cin >> no >> ed;
	vector<vector<int>> nodes(no);
	vector<bool> m(no,false);
	marked = m;
	for(int i = 0; i < ed;++i){
		int n1,n2;
		cin >> n1 >> n2;
		if(trans.count(n1) == 0)
			trans[n1] = t++;
		if(trans.count(n2) == 0)
			trans[n2] = t++;
		nodes[trans[n1]].push_back(trans[n2]);
		nodes[trans[n2]].push_back(trans[n1]);
	}
	int head;
	cin >> head;
	dfs(nodes,trans[head]);
	cout << no - total << endl;
	return 0;
}