/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

vector<int> bfs(vector<vector<int>> &graph,int start){
	bool visited[graph.size()];
	memset(visited,false,sizeof(visited));
	queue<int> toVisit;
	toVisit.push(start);
	while(toVisit.size()){
		int visit = toVisit.front();
		toVisit.pop();
		for(int i = 0; i < graph[visit].size();++i){
			if(visited[graph[visit][i]] == false){
				visited[graph[visit][i]] = true;
				toVisit.push(graph[visit][i]);
			}
		}
	}
	vector<int> ans;
	for(int i = 1;i < graph.size();++i){
		if(!visited[i])
			ans.push_back(i);
	}
	return ans;
}

int main(){
	while(true){
		int siz;
		cin >> siz;
		if(siz == 0)
			break;
		vector<vector<int>> graph(siz+1);
		int first;
		bool dod = true;
		cin >> first;
		if(first == 0)
			dod = false;
		//int co = first;
		bool take = false;
		while(dod){
			int add;
			cin >> add;
			if(take && add != 0){
				first = add;
				take = false;
				continue;
			}
			if(add == 0 && !take){
				take = true;
				continue;
			}
			if(add == 0)
				break;
			graph[first].push_back(add);
		}
		int many;
		cin >> many;
		for(int i = 0; i < many;++i){
			int wanted;
			cin >> wanted;
			vector<int> show = bfs(graph,wanted);
			cout << show.size();
			for(int j = 0; j < show.size();++j){
				cout << " " << show[j];
			}
			cout << endl;
		}
	}
	return 0;
}