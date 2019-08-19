#include<iostream>
#include<vector>
#define min(x,y)(x < y?x:y)

using namespace std;

vector<int> cost(200000);
vector<int> low_dfs(200000,-1);
vector<int> dfs_num(200000,-1);
vector<bool> visited(200000,false);
vector<int> S;
int ans = 0;
int counter = 0;

void SCC(int s,vector<vector<int>> &graph){
	visited[s] = true;
	dfs_num[s] = low_dfs[s] = counter++;
	S.push_back(s);
	for(int j = 0; j < (int)graph[s].size();++j){
		if(dfs_num[graph[s][j]] == -1)
			SCC(graph[s][j],graph);
		if(visited[graph[s][j]])
			low_dfs[s] = min(low_dfs[s],low_dfs[graph[s][j]]);
	}
	if(dfs_num[s] == low_dfs[s] && low_dfs[graph[s][0]] == dfs_num[s]){
		int toAdd = 100000;
		for(int i = 0;i < S.size();++i){
			if(low_dfs[S[i]] == low_dfs[s]){
			    toAdd = min(toAdd,cost[S[i]]);
			}
		}
		ans += toAdd;
		S.clear();
	}
}

int main(){
	int n;
	scanf(" %d",&n);
	vector<vector<int>> graph(n);
	for(int i = 0; i < n;++i)
		scanf(" %d",&cost[i]);
	for(int i = 0; i < n;++i){
		int val;
		scanf(" %d",&val);
		--val;
		graph[i].push_back(val);
	}
	for(int i = 0; i < n;++i){
		if(!visited[i])
			SCC(i,graph);
	}
	printf("%d\n",ans);
	return 0;
}