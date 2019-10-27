/**
* I only hope everything will be back to normal
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int n,m,s;
		scanf(" %d %d %d",&n,&m,&s);
		vector<vector<int>> graph(n+1);
		while(m--){
			int a,b;
			scanf(" %d %d",&a,&b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		vector<pair<int,int>> sold(s);
		for(int i = 0; i < s;++i) cin >> sold[i].first >> sold[i].second;
		vector<int> dist(n+1,-1);
		int visi = 0;
		bool posi = 1;
		vector<int> marked(n+1,-1);
		for(int i = 0; i < sold.size() && posi;++i){
			queue<int> q;
			if(dist[sold[i].first] == -1){
				++visi;
				dist[sold[i].first] = i;
			}
			else{
				posi = 0;
				break;
			}
			marked[sold[i].first] = 0;
			q.push(sold[i].first);
			while(q.size() && posi){
				int f = q.front();q.pop();
				for(int j = 0; j < graph[f].size();++j){
					if(marked[f] + 1 <= sold[i].second && (dist[graph[f][i]] != -1 && dist[graph[f][i]] != i)){
						posi = 0;
						break;
					}
					if(dist[graph[f][j]] == -1 && marked[f] + 1 <= sold[i].second){
						marked[graph[f][j]] = marked[f] +1;
						q.push(graph[f][j]);
						++visi;
						dist[graph[f][j]] = i;
					}
				}
			}
		}
		//cout << visi << endl;
		if(visi == n && posi)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}