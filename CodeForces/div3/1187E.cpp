/**
* I'm not doing this for you
* or I do?
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#define max(x,y)(x > y? x:y)
#define ll long long

using namespace std;

map<pair<int,int>,ll> dp;
bool marked[200000];

int bfs(int start, vector<vector<int>> &graph){
	bool mark[graph.size()];
	memset(mark,false,sizeof(mark));
	mark[start] = true;
	//marked[start] = true;
	queue<int> q;
	q.push(start);
	int ans = 1;
	while(q.size()){
		int f = q.front();q.pop();
		for(int i = 0; i < (int)graph[f].size();++i){
			if(!(marked[graph[f][i]] || mark[graph[f][i]])){
				mark[graph[f][i]] = true;
				q.push(graph[f][i]);
				++ans;
			}
		}
	}
	return ans;
}


ll solve(int s,int l, vector<vector<int>> &graph){
	if(dp[make_pair(s,l)] != -1){
		//cout << "here?" << endl;
		return dp[make_pair(s,l)];	
	}
	marked[s] = true;
	ll ans = bfs(s,graph);
	for(int i = 0; i < graph[s].size();++i){
		if(!marked[graph[s][i]]){
			ans += solve(graph[s][i],s,graph);
		}
	}
	return dp[make_pair(s,l)] = ans;
}


int main(){
	dp.clear();
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for(int i = 0;i < n-1;++i){
		int a,b;
		cin >> a >> b;
		--a;--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		dp[make_pair(a,b)] = -1;
		dp[make_pair(a,-1)] = -1;
		dp[make_pair(b,-1)] = -1;
		dp[make_pair(b,a)] = -1;
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ans = max(ans,solve(i,-1,graph));
	//	cout << "ans is " << ans << " i is " << i << endl;
		memset(marked,false,n);
	}
	cout << ans << endl;
	return 0;
}