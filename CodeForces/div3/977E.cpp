/**
* I'm an Idiot(mf)
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

bool marked[200000];
vector<vector<int>> graph(200000);
vector<int> BFS(int start){
	vector<int> ans;
	if(marked[start])
		return ans;
	queue<int> q;
	q.push(start);
	while(q.size()){
		int f = q.front();q.pop();
		marked[f] = true;
		//cout << f << endl;
		ans.push_back(f);
		for(int i = 0; i < (int)graph[f].size();++i){
			if(!marked[graph[f][i]])
				q.push(graph[f][i]);
		}
	}
	return ans;
}

int main(){
	memset(marked,false,sizeof(marked));
	int N,E;
	cin >> N >> E;
	while(E--){
		int from, to;
		cin >> from >> to;
		--from;--to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	int ans = 0;
	//cout << "herell" << endl;
	for(int i = 0; i < N;++i){
		vector<int> check = BFS(i);
	//	cout << "here? " << endl;
		if(check.size() == 0)
			continue;
		bool posi = true;
		for(int j = 0; j < check.size();++j){
			if(graph[check[j]].size() != 2){
				posi = false;
				break;
			}
		}
		if(posi){
			//cout << i << endl;
			++ans;
		}
	}
	cout << ans << endl;
}