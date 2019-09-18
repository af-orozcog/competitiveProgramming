#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	short fi = 0;
	while(t--){
		if(fi)
			puts("");
		int n;
		scanf(" %d",&n);
		vector<vector<int>> graph(n);
		for(int i = 0; i < n;++i){
			int go,ma; scanf(" %d %d",&go,&ma);
			for(int j = 0; j < ma;++j){
				int va;scanf(" %d",&va);
				graph[go].push_back(va);
			}
		}
		int from,to; scanf(" %d %d",&from,&to);
		vector<int> dist(n,-1);
		queue<int> q;
		q.push(from);
		dist[from] = 0;
		while(q.size() && dist[to] == -1){
			int f = q.front();q.pop();
			for(int i = 0; i < graph[f].size();++i){
				if(dist[graph[f][i]] == -1){
					dist[graph[f][i]] = dist[f] + 1;
					q.push(graph[f][i]);
				}
			}
		}
		printf("%d %d %d\n",from,to,dist[to]-1);
		fi = 1;
	}
	return 0;
}