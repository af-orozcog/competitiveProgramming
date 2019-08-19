#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define ll long long

using namespace std;

vector<int> bfs(vector<vector<int>> &graph){
	vector<int> ans;
	queue<int> q;
	int marked[graph.size()];
	memset(marked,-1,sizeof(marked));
	q.push(0);
	marked[0] = 0;
	while(q.size()){
		int f = q.front();q.pop();
		for(int i = 0; i < (int)graph[f].size();++i){
			if(marked[graph[f][i]] == -1){
				q.push(graph[f][i]);
				if(marked[f] == 1)
					marked[graph[f][i]] = 0;
				else{
					marked[graph[f][i]] = 1;
					ans.push_back(graph[f][i]);
				}
			}
		}
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for(int i = 0; i < n-1;++i){
		int a,b;
		cin >> a >> b;
		--a;--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> che = bfs(graph);
	//cout << che << endl;
	ll com = n - che.size();
	ll ans = 0;
	for(int i = 0; i < che.size();++i){
		ans += com - graph[che[i]].size();
	}
	cout << ans << endl;
	return 0;
}