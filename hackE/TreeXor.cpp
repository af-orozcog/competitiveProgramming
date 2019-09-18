#include<iostream>
#include<vector>
#define min(x,y)(x < y?x:y)
#define max(x,y)(x > y?x:y)

using namespace std;

vector<int> mark(100001,-1);
int k;

void dfs(int s, int c,vector<vector<int>> &graph){
	mark[s] = c;
	int next = c;
	if(graph[s].size() >= k)
		next = next ^ s;
	for(int i = 0; i < graph[s].size();++i){
		dfs(graph[s][i],next,graph);
	}
}

int main(){
	int n;
	scanf(" %d %d",&n,&k);
	vector<vector<int>> graph(n+1);
	for(int i = 0; i < n-1;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		graph[min(a,b)].push_back(max(a,b));
	}
	dfs(1,0,graph);
	for(int i = 1;i <= n;++i)
		printf("%d\n", mark[i]);
	return 0;
}