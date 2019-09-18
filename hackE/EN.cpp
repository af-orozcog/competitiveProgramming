#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long

using namespace std;

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	int que[m];
	for(int i = 0; i < m;++i) scanf(" %d",&que[i]);
	vector<vector<int>> graph(n);
	for(int i = 1;i < n;++i){
		int va; scanf(" %d",&va);
		--va;
		graph[va].push_back(i);
	}
	vector<int> dist(n,-1);
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while(q.size()){
		int f = q.front();q.pop();
		for(int i = 0; i < (int) graph[f].size();++i){
			if(dist[graph[f][i]] == -1){
				dist[graph[f][i]] = dist[f] + 1;
				q.push(graph[f][i]);
			}
		}
	}
	sort(dist.begin(),dist.end());
	ll ans = 0;
	for(int i = 0; i < m;++i){
		int index = lower_bound(dist.begin(),dist.end(),que[i]) - dist.begin();
		ans += (ll)((ll)n-(ll)index);
	}
	printf("%lld\n",ans);
	return 0;
}