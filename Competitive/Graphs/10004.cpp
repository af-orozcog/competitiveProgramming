/**
* I'm an Idiot
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int BLUE = 1;
int RED = 2;

bool BFS(int start,vector<vector<int>> &graph){
	int marked[graph.size()];
	memset(marked,0,sizeof(marked));
	queue<int> q;
	marked[start] = RED;
	q.push(start);
	bool ans = true;
	while(q.size() && ans){
		int f = q.front();q.pop();
		for(int i = 0; i < (int)graph[f].size();++i){
			if(marked[graph[f][i]] == 0){
				if(marked[f] == BLUE)
					marked[graph[f][i]] = RED;
				else
					marked[graph[f][i]] = BLUE;
				q.push(graph[f][i]);
			}
			else if(marked[graph[f][i]] == marked[f]){
				ans = false;
				break;
			}
		}
	}
	return ans;
}
int main(){
	while(true){
		int N;
		cin >> N;
		if(N == 0)
			break;
		vector<vector<int>> graph(N);
		int E;
		cin >> E;
		while(E--){
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
		cout << (BFS(0,graph)?"BICOLORABLE":"NOT BICOLORABLE")<<".\n";
	}
	return 0;
}