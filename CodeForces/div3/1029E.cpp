/**
* I hope everything will be as before
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<vector<int>> graph(n);
	for(int i = 1;i < n; ++i){
		int a,b;cin>> a >> b;
		--a;--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> dist(n,-1);
	dist[0] =0;
	queue<int> q;
	q.push(0);
	while(q.size()){
		int f = q.front();q.pop();
		for(int i = 0; i < graph[f].size();++i){
			if(dist[graph[f][i]] == -1){
				dist[graph[f][i]] = dist[f] + 1;
				q.push(graph[f][i]);
			}
		}
	}
	map<int,int> fr;
	int upTo = 0;
	for(int i = 1; i < n;++i){
		if(fr.count(dist[i]))
			++fr[dist[i]];
		else
			fr[dist[i]] = 1;
		upTo = max(upTo,dist[i]);
	}
	int dp[2][200003];
	memset(dp,0,sizeof(dp));
	for(auto i = fr.rbegin(); i != fr.rend();++i){
		pair<int,int> it = (*i);
		if(it.first == 1)
			break;
		if(it.first + 1 <= upTo){
			dp[0][it.first] = it.second+dp[1][it.first+1];
			dp[1][it.first] = min(it.second+dp[1][it.first+1],dp[0][it.first+1]);
		}
		else
			dp[0][it.first] = it.second;
	}
	cout << dp[1][2] << endl;
	return 0;
}