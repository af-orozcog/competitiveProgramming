#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int bfs(int s, vector<vector<int>> &graph){
	vector<int> dist1(graph.size(),-1);
	dist1[0] = 0;
	queue<int> q;
	q.push(0);
	while(q.size()){
		int f = q.front();q.pop();
		for(int j = 0; j < (int)graph[f].size();++j){
			if(dist1[graph[f][j]] == -1){
				dist1[graph[f][j]] = dist1[f] + 1;
				q.push(graph[f][j]);
			}
		}
	}
//	cout << "entro" << endl;
	vector<int> dist2(graph.size(),-1);
	dist2[s] = 0;	
	q.push(s);
	while(q.size()){
		int f = q.front();q.pop();
		for(int j = 0; j < (int)graph[f].size();++j){
			if(dist2[graph[f][j]] == -1){
				dist2[graph[f][j]] = dist2[f] + 1;
				q.push(graph[f][j]);
			}
		}
	}
	int max = 0;
	for(int i = 0; i < dist2.size();++i){
		if(dist2[i] < dist1[i]){
			if(dist1[i] > max)
				max = dist1[i];
		}
	}
	return 2*max;
}

int main(){
	int n,x;
	scanf(" %d %d",&n,&x);
	--x;
	vector<vector<int>> graph(n);
	for(int i = 0; i < n-1;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		--a;--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	} 
	printf("%d\n",bfs(x,graph));
	return 0;
}