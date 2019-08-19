#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N;
bool marked[1000];

int DFS(int start,vector<vector<int>> &graph){
	marked[start] = true;
	if(!marked[graph[start][0]])
		return DFS(graph[start][0],graph);
	else
		return graph[start][0];
}

int main(){
	cin >> N;
	vector<vector<int>> graph(N);
	for(int i = 0; i < N;++i){
		int to;
		cin>> to;
		--to;
		graph[i].push_back(to);
	}
	for(int i = 0; i < N;++i){
		memset(marked,false,sizeof(marked));
		if(i == 0)
			cout << DFS(i,graph)+1;
		else
			cout <<" " <<DFS(i,graph)+1; 
	}
	cout << endl;
	return 0;
}