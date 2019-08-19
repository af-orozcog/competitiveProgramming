#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool bfs(vector<vector<int>> &graph){
	queue<int> q;
	q.push(0);
	bool ans = 1;
	while(q.size() && ans){
		int f = q.front();q.pop();
		int po = 0;
		for(int i = 0; i < graph[f].size();++i){
			if(graph[graph[f][i]].size() == 0)
				++po;
			q.push(graph[f][i]);
		}
		if(po < 3 && graph[f].size())
			ans = false;
	}
	return ans;
}

int main(){
	int n;
	scanf(" %d",&n);
	vector<vector<int>> graph(n);
	for(int i = 1;i < n;++i){
		int a;
		scanf(" %d",&a);
		--a;
		graph[a].push_back(i);
	}
	if(bfs(graph))
		puts("Yes");
	else
		puts("No");
	return 0;
}