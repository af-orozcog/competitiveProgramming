#include<iostream>
#include<vector>
#define min(x,y)(x < y ? x:y)
#define M 1e-10000000

using namespace std;
typedef pair<int,double> pii;
vector<int> dfs_num,dfs_low,S,visited;
int dfsNumberCounter;
bool val = false;

void tarjanSCC(int u, vector<vector<pii>> &graph){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for(int i = 0; i < graph[u].size();++i){
		pii v = graph[u][i];
		if(dfs_num[v.first] == 0)
			tarjanSCC(v.first);
		if(visited[v.first])
			dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);
	}
	if(dfs_low[u] == dfs_num[u]){
		int last = S.back();
		S.pop_back();
		double vals = 1.0;
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			vals *= graph[v][last].second;
			last = v;
			if(u == v) break;
		}
		if((vals - 1.1) >= 0.0)
			val = true;
	}
}

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	vector<vector<pii>> graph(n);
	for(int i = 0; i < m;++i){
		int a,b;double c;
		cin >> a >> b >> c;
		--a;--b;
		graph[a].push_back({b,c});
	}
	
}