#include<iostream>
#include<vector>
#include<queue>
#define ll long long

using namespace std;

ll bfs(int from,int to,vector<vector<pair<int,ll>>> &graph){
	vector<ll> dist(graph.size(),-1);
	dist[from] = 0;
	queue<int> q;
	q.push(from);
	while(q.size() && dist[to] == -1){
		int f= q.front();q.pop();
		for(int i = 0; i < graph[f].size();++i){
			if(dist[graph[f][i].first] == -1){
				dist[graph[f][i].first] = dist[f] + graph[f][i].second;
				q.push(graph[f][i].first);
			}
		}
	}
	return dist[to];
}

int main(){
	while(1){
		int n;
		scanf(" %d",&n);
		if(n == 0)
			break;
		vector<vector<pair<int,ll>>> graph(n);
		for(int i = 1; i < n;++i){
			int a;
			ll c;
			cin >> a >> c;
			graph[i].push_back(make_pair(a,c));
			graph[a].push_back(make_pair(i,c));
		}
		int q;
		scanf(" %d",&q);
		for(int i = 0; i < q;++i){
			int from,to;
			scanf(" %d %d",&from,&to);
			if(i)
				cout << " "<<bfs(from,to,graph);
			else cout << bfs(from,to,graph);
		}
		puts("");
	}
	return 0;
}