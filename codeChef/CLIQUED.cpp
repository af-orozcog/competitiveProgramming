#include<iostream>
#include<vector>
#include<queue>
#define ll long long

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int old,tot;
		cin >> tot >> old;
		vector<vector<pair<int,ll>>> graph(tot+1);
		ll dis;
		cin >> dis;
		dis = dis << 1;
		for(int i = 0; i < old;++i){
			graph[i].push_back(make_pair(tot,(dis>>1)));
			graph[tot].push_back(make_pair(i,(dis>>1)));
		}
		int m,st;
		cin >> m >> st;
		--st;
		for(int i = 0; i < m;++i){
			int a,b;
			ll c;
			cin >> a >> b;
			cin >> c;
			c = c << 1;
			--a;--b;
			graph[a].push_back(make_pair(b,c));
			graph[b].push_back(make_pair(a,c));
		}
		vector<ll> dist(graph.size(),1000000000000);
		dist[st] = 0;
		priority_queue<pair<ll,int>> q;
		q.push(make_pair(0,-st));
		while(q.size()){
			ll c = -q.top().first;int u = -q.top().second;
			q.pop();
			if(dist[u] < c)
				continue;
			for(int i = 0; i <(int)graph[u].size();++i){
				ll wp = graph[u][i].second;int w = graph[u][i].first;
				if(dist[u] + wp < dist[w]){
					dist[w] = dist[u] + wp; 
					q.push(make_pair(-dist[w],-w));
				}
			}
		}
		for(int i = 0; i < tot;++i){
			if(i == 0)
				cout << (dist[i]>>1);
			else
				cout << " "<< (dist[i]>>1);
		}
		puts("");
	}
	return 0;
}