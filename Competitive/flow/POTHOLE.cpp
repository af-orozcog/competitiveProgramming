/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<climits>
#define min(x,y)(x < y?x:y)
using namespace std;

int graph[210][210];
int siz;
//int small = INT_MAX;
bool bfs(){
	//cout << "entered " << endl;
	queue<int> toVisit;
	toVisit.push(0);
	int parent[siz];
	bool visited[siz];
	memset(parent,-1,sizeof(parent));
	memset(visited,false,sizeof(visited));
	visited[0] =  true;
	while(toVisit.size()){
		int visit = toVisit.front();
		toVisit.pop();
		if(visit == siz-1)
			break;
		//cout << "visiting " << visit << endl;
		for(int i = 0; i < siz;++i){
			if(visited[i]== false && graph[visit][i] > 0){
				parent[i] = visit;
				visited[i] = true;
				toVisit.push(i);
		//		cout <<"aa "<< i << endl;
			}
		}
	}
	for(int i = siz-1; parent[i] >-1;i = parent[i]){
		int dad = parent[i];
		//cout << dad << endl;
		--graph[dad][i];
		++graph[i][dad];
	}
	return visited[siz-1];
}

int main(){
	int cas;
	scanf(" %d",&cas);
	while(cas--){
		memset(graph,0,sizeof(graph));
		int total = 0;
		scanf(" %d",&siz);
		for(int i = 0; i < siz-1;++i){
			int to;
			scanf(" %d",&to);
			//cout << "to " << to << endl;
			for(int j = 0; j < to;++j){
				int connect;
				scanf(" %d",&connect);
				--connect;
			//	cout << " "
				if(i == 0|| connect == siz - 1)
					graph[i][connect] = 1;
				else
					graph[i][connect] = INT_MAX;
			}
		}
		//cout << "lel" << endl;
		//small = INT_MAX;
		while(bfs()){
		//	cout << "aqui? " << endl;
			++total;
		}
		printf("%d\n",total);
	}
	return 0;
}