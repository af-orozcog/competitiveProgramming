#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>

using namespace std;


int bfs(int s, vector<vector<int>>&graph,int m){
	int dist[graph.size()];
	memset(dist,-1,sizeof(dist));
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	int ans = 1;
	while(q.size()){
		int f = q.front();q.pop();
		for(int i = 0; i < (int)graph[f].size();++i){
			if(dist[graph[f][i]] == -1){
				dist[graph[f][i]] = dist[f] +1;
				if(dist[f] + 1 <= m){
					q.push(graph[f][i]);
					++ans;
				}
			}
		}
	}
	return graph.size() - ans;
}

int main(){
	int cas = 0;
	while(true){
		int N;
		cin >> N;
		if(N == 0)
			break;
		map<int,int> unique;
		int n = 0; 
		vector<pair<int,int>> edge;
		while(N--){
			int a,b;
			cin >> a >> b;
			if(unique.count(a) == 0)
				unique[a] = n++;
			if(unique.count(b) == 0)
				unique[b] = n++;
			edge.push_back(make_pair(unique[a],unique[b]));
		}
		vector<vector<int>> graph(unique.size());
		for(int i = 0; i < edge.size();++i){
			graph[edge[i].first].push_back(edge[i].second);
			graph[edge[i].second].push_back(edge[i].first);
		}
		while(true){
			int a,b;
			cin >> a >> b;
			if(a == 0)
				break;
			int ans = bfs(unique[a],graph,b);
			cout << "Case " << ++cas << ": " << ans << " nodes not reachable from node " << a << " with TTL = " << b << ".\n";
		}
	}
	return 0;
}