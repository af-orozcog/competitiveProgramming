#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define min(x,y)(x < y? x:y)

using namespace std;

int bfs(int s,vector<vector<pair<int,int>>> &graph){
	int ans1 = 0;
	int ans2 = 0;
	bool visited[graph.size()];
	memset(visited,false,sizeof(visited));
	queue<int> q;
	visited[s] = true;
	q.push(graph[s][0].first);
	ans1 += graph[s][1].second;
	visited[graph[s][0].first] = true;
	while(q.size()){
		int f = q.front();q.pop();
		for(int i = 0; i < (int)graph[f].size();++i){
			if(!visited[graph[f][i].first]){
				q.push(graph[f][i].first);
				visited[graph[f][i].first] = true;
				if(graph[f][i].second < 0){
					ans1+= -graph[f][i].second;
				}
			}
		}
	}
	memset(visited,false,sizeof(visited));
	q.push(graph[s][1].first);
	ans2 += graph[s][0].second;
	visited[s] = true;
	visited[graph[s][1].first] = true;
	while(q.size()){
		int f = q.front();q.pop();
		for(int i = 0; i < (int)graph[f].size();++i){
			if(!visited[graph[f][i].first]){
				q.push(graph[f][i].first);
				visited[graph[f][i].first] = true;
				if(graph[f][i].second < 0){
					ans2+= -graph[f][i].second;
				}
			}
		}
	}
	return min(ans1,ans2);
}

int main(){
	int n;
	cin >> n;
	vector<vector<pair<int,int>>> graph(n);
	for(int i = 0; i < n;++i){
		int a,b,c;
		cin >> a >> b >> c;
		--a;--b;
		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a,-c));
	}
	int lo = -1;
	for(int i = 0; i < n;++i){
		if(graph[i][0].second > 0 && graph[i][1].second > 0){
			lo = i;
			break;
		}
	}
	if(lo == -1){
		cout << 0 << endl;
		return 0;
	}
	cout << bfs(lo,graph) << endl;
}