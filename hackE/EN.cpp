#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

bool visited[200000];
int dfs(int s, vector<vector<int>> &graph, vector<int> &tar,int dist, int i){
	visited[s] = true;
	ll ans = 0;
	if(dist == tar[i]){
		++ans;
		++i;
	}
	if(i == tar.size())
		return ans;
	for(int i = 0; i < (int)graph[s].size();++i){
		if(!visited[graph[s][i]]){
			ans += dfs(graph[s][i],graph,tar,dist + 1,i);
		}
	}
	return ans;
}

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	vector<vector<int>> graph(n);
	vector<int> targets(m);
	for(int i = 0; i < m;++i){
		scanf(" %d",&targets[i]);
	}
	sort(targets.begin(),targets.end());
	for(int i = 1; i < n;++i){
		int val;
		scanf(" %d",&val);
		--val;
		graph[val].push_back(i);
		graph[i].push_back(val);
	}
	ll ans = 0;
	for(int i = 0; i < n;++i){
		memset(visited,false,n);
		ans += dfs(i, graph, targets, 0,0);
	}
	printf("%lld\n",ans);
	return 0;
}