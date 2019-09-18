#include<iostream>
#include<vector>
#define min(x,y)(x < y?x:y)
#define max(x,y)(x > y? x:y)

using namespace std;

vector<int> marked(100000,0);
int ans = 0;

void dfs(int s, vector<vector<int>> &graph){
	for(int i = 0; i < graph[s].size();++i){
		if(marked[graph[s][i]] == 0){
			marked[graph[s][i]] = graph[graph[s][i]].size()-1;
			if(marked[s] < marked[graph[s][i]])++ans;
			dfs(graph[s][i],graph);
		}
	}
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
	for(int i = 0; i < n;++i){
		if(marked[i] == 0){
			marked[i] = graph[i].size();
			dfs(i,graph);
		}
	}
	printf("%d\n", ans);
	return 0;
}