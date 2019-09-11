#include<iostream>
#include<queue>
#include<vector>
#include<map>

using namespace std;

int bfs(vector<vector<int>> &graph, int to){
	vector<int> dist(graph.size(),-1);
	dist[0] = 1;
	queue<int> q;
	q.push(0);
	int last = 0;
	int ans = 1;
	while(q.size() && dist[last] < to){
		int f= q.front();q.pop();
		int count = 0;
		for(int i = 0; i < graph[f].size();++i){
			if(dist[graph[f][i]] == -1){
				dist[graph[f][i]] = dist[f] + 1;
				q.push(graph[f][i]);
				++count;
				last = graph[f][i];
			}
		}
		ans = count;
	}
	return ans;
}

int main(){
	int n;
	scanf(" %d",&n);
	vector<vector<int>> graph(n);
	for(int i = 0; i < n-1;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		--a;--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int to;
	scanf(" %d",&to);
	printf("%d\n",bfs(graph,to));
	return 0;
}