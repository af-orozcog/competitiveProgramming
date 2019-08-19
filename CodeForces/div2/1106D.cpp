#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> bfs(vector<vector<int>> &graph){
	vector<int> ans;
	vector<bool> visited(graph.size(),false);
	priority_queue<int> q;
	q.push(0);
	visited[0] = true;
	while(q.size()){
		int f = -q.top();q.pop();
		ans.push_back(f);
		for(int i = 0; i < (int)graph[f].size();++i){
			if(!visited[graph[f][i]]){
				visited[graph[f][i]] = true;
				q.push(-graph[f][i]);
			}
		}
	}
	return ans;
}

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	vector<vector<int>> graph(n);
	for(int i = 0; i < m;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		--a;--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> toP = bfs(graph);
	for(int i = 0; i < n;++i){
		if(i == 0)
			printf("%d",toP[i]+1);
		else
			printf(" %d",toP[i]+1);
	}
	puts("");
	return 0;
}