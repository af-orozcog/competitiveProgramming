#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;


vector<vector<int>> bfs(int start,vector<vector<int>> &graph){
	int marked[graph.size()];
	memset(marked,-1,sizeof(marked));
	queue<int> q;
	q.push(start);
	marked[start] = 0;
	vector<vector<int>> ans(2);
	ans[0].push_back(start);
	while(q.size()){
		int f = q.front();q.pop();
		for(int i = 0; i < graph[f].size();++i){
			if(marked[graph[f][i]] == -1){
				if(marked[f] == 0){
					marked[graph[f][i]] = 1;
					ans[1].push_back(graph[f][i]);
				}
				else{
					marked[graph[f][i]] = 0;
					ans[0].push_back(graph[f][i]);
				}
				q.push(graph[f][i]);
			}
		}
	}
	return ans;
}


int main(){
	int que;
	cin >> que;
	while(que--){
		int n,e;
		cin >> n >> e;
		vector<vector<int>> graph(n);
		for(int i = 0; i < e;++i){
			int a,b;
			cin >> a >> b;
			--a;--b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		if(n == 2){
			cout << 1 << endl << 1 << endl;
			continue;
		}
		vector<vector<int>> g = bfs(0,graph);
		int j;
		if(g[0].size() < g[1].size())
			j = 0;
		else
			j = 1;
		cout << g[j].size() << endl;
		for(int i = 0; i < g[j].size();++i){
			if(i == 0)
				cout << g[j][i]+1;
			else
				cout << " " << g[j][i]+1;
		}
		cout << endl;
	}
	return 0;
}