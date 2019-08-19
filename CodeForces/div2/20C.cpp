#include<iostream>
#include<queue>
#include<vector>
#define ll long long

using namespace std;

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	vector<vector<pair<int,ll>>> graph(n);
	for(int i = 0; i < m;++i){
		int a,b;
		ll c;
		scanf(" %d %d",&a,&b);
		--a;--b;
		cin >> c;
		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a,c));
	}
	vector<ll> dist(n,1000000000000000);
	vector<int> dad(n,-1);
	dad[0] = 0;
	dist[0] = 0;
	priority_queue<pair<ll,int>> q;
	q.push(make_pair(0,0));
	while(q.size()){
		int f = -q.top().second;ll d = -q.top().first;
		q.pop();
		if(d > dist[f])
			continue;
		for(int i = 0; i < graph[f].size();++i){
			if(dist[f] + graph[f][i].second < dist[graph[f][i].first]){
				dist[graph[f][i].first] = dist[f] + graph[f][i].second;
				dad[graph[f][i].first] = f;
				q.push(make_pair(-dist[graph[f][i].first],-graph[f][i].first));
			}
		}
	}
	if(dad[n-1] == -1){
		puts("-1");
		return 0;
	}
	vector<int> ans;
	int s = n-1;
	while(dad[s] != s){
		ans.push_back(s);
		s = dad[s];
	}
	ans.push_back(0);
	for(int i = ans.size()-1;i >= 0;--i){
		if(i == ans.size()-1)
			printf("%d",ans[i]+1);
		else
			printf(" %d",ans[i]+1);
	}
	puts("");
	return 0;
}