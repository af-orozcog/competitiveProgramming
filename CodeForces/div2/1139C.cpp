/**
*
*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define ll long long

using namespace std;

ll M = 1000000007;
int N;
int K;
bool marked[100000];

ll BFS(int s,vector<vector<pair<int,int>>>&graph){
	if(marked[s])
		return 0;
	int pa = 0;
	queue<int> q;
	q.push(s);
	marked[s] = true;
	while(q.size()){
		++pa;
		int f = q.front();q.pop();
		for(int i = 0; i < (int)graph[f].size();++i){
			if(!marked[graph[f][i].first] && graph[f][i].second == 0){
				q.push(graph[f][i].first);
				marked[graph[f][i].first] = true;
			}
		}
	}
	ll ans = 1;
	for(int i = 0; i < K;++i){
		ans *= pa;
		ans = ans % M;
	}
	return ans;
}

int main(){
	memset(marked,false,sizeof(marked));
	cin >>N >>K;
	vector<vector<pair<int,int>>> graph(N);
	for(int i =1;i < N;++i){
		int f,t,c;
		cin >> f >> t >> c;
		--f;--t;
		graph[f].push_back(make_pair(t,c));
		graph[t].push_back(make_pair(f,c));
	}
	ll ans = 1;
	for(int i = 0; i < K;++i){
		ans *= N;
		ans = ans % M; 
	}
	for(int i = 0; i < graph.size();++i){
		ans -= BFS(i,graph);
		if(ans < 0)
			ans += M;
		else	
			ans = ans % M;
	}
	cout << ans << endl;
	return 0;
}