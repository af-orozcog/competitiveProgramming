#include<iostream>
#include<vector>
#include<queue>
#define M 1000000000

using namespace std;
typedef vector<vector<pair<int,int>>> vip;


int main(){
	int t;
	scanf(" %d",&t);
	for(int we= 0; we < t;++we){
		int n,m,s,d;
		scanf(" %d %d %d %d",&n,&m,&s,&d);
		vip graph(n);
		for(int i = 0; i < m;++i){
			int a,b,c;
			scanf(" %d %d %d",&a,&b,&c);
			graph[a].push_back({b,c});
			graph[b].push_back({a,c});
		}
		vector<int> dist(n,M);
		dist[s] = 0;
		priority_queue<pair<int,int>> pq;
		pq.push({0,s});
		while(pq.size()){
			int f = pq.top().second;int va = -pq.top().first;
			pq.pop();
			if(dist[f] < va)
				continue;
			for(int i = 0; i < graph[f].size();++i){
				if(dist[graph[f][i].first] > dist[f] + graph[f][i].second){
					dist[graph[f][i].first] = dist[f] + graph[f][i].second;
					pq.push({-dist[graph[f][i].first],graph[f][i].first});
				}
			}
		}
		printf("Case #%d: ",we+1);
		if(dist[d] == M)
			puts("unreachable");
		else
			printf("%d\n",dist[d]);
	}
	return 0;
}