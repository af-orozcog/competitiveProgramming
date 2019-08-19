#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int coun;

void dfs(int s, int to,vector<vector<int>>&graph){
	//cout << s <<" " <<coun<<endl;
	priority_queue<int> q;
	for(int i = 0; i < (int)graph[s].size();++i){
		if(graph[s][i] > s)
			q.push(-graph[s][i]);
	}
	++coun; 
	if(coun == to){
		printf("%d\n",s+1);
		return;
	}
	while(q.size()){
		int f = -q.top();q.pop();
 		dfs(f,to,graph);
		if(coun >= to)
			return;
	}
	return ;
}

int main(){
	int n,q;
	scanf(" %d %d",&n,&q);
	vector<vector<int>> graph(n);
	for(int i = 1; i < n;++i){
		int v;
		scanf(" %d",&v);
		--v;
		graph[i].push_back(v);
		graph[v].push_back(i);
	}
	while(q--){
		coun = 0;
		int s,to;
		scanf(" %d %d",&s,&to);
		--s;
		if(to == 1){
			printf("%d\n",s+1);
			continue;
		}
		dfs(s,to,graph);
		if(coun < to)
			puts("-1");
	}
	return 0;
}