/**
* I do this because of Valentina, she motivates me :)
*/
#include<iostream>
#include<vector>
#include<queue>
#define ll long long

using namespace std;

int main(){
	freopen("awesome.in", "r", stdin);
	int t;
	scanf(" %d",&t);
	while(t--){
		int n,l,r;
		scanf(" %d %d %d",&n,&l,&r);
		vector<vector<int>> graph(n);
		for(int i = 0; i < n-1;++i){
			int a,b;
			scanf(" %d %d",&a,&b);
			--a;--b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		//cout << "lel" << endl;
		ll ways = 0;
		for(int i = 0; i< n;++i){
			vector<int> dis(n,-1);
			dis[i] = 0;
			queue<int> q;
			q.push(i);
			while(q.size()){
				int f = q.front();q.pop();
				for(int j = 0; j < graph[f].size();++j){
					if(dis[graph[f][j]] == -1){
						dis[graph[f][j]] = dis[f] + 1;
						if(((n-1) - dis[graph[f][j]] >= l) && ((n-1) - dis[graph[f][j]] <= r))
							++ways;
						//dist[i][graph[f][j]] = dis[graph[f][j]];
						q.push(graph[f][j]);
					}
				}
			}
		}
		cout << (ways>>1) << endl;
	}
	return 0;
}