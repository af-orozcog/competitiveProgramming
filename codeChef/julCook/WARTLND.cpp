#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define ll long long

using namespace std;

bool visited[10000];

ll gcd(ll a, ll b){
	return b == 0? a : gcd(b,a %b);
}

ll bfs(int s, vector<vector<pair<int,ll>>> &graph){
	vector<ll> dist(graph.size(),-1);
	visited[s] = true;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	ll ans = 0;
	while(q.size()){
		int f = q.front();q.pop();
		for(int j = 0; j < (int)graph[f].size();++j){
			if(dist[graph[f][j].first] == -1){
				dist[graph[f][j].first] = gcd(dist[f],graph[f][j].second);
				q.push(graph[f][j].first);
				if(!visited[graph[f][j].first])
					ans += dist[graph[f][j].first];
			}
		}
	}
	return ans;
}

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int n;
		scanf(" %d",&n);
		memset(visited,false,sizeof(n));
		vector<vector<pair<int,ll>>> graph(n);
		for(int i = 0; i < n-1;++i){
			int a,b;
			ll d;
			scanf(" %d %d",&a,&b);
			cin >> d;
			--a;--b;
			graph[a].push_back(make_pair(b,d));
			graph[b].push_back(make_pair(a,d));
		}
		ll ans = 0;
		for(int i = 0; i < n;++i){
			ans += bfs(i,graph);
		}
		cout << ans<< endl;
	}
}