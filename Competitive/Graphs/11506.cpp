#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#define min(x,y)(x < y? x:y)

using namespace std;

int graph[120][120];

int bfs(int m){
	vector<bool> visited(120,false);
	vector<int> dad(120,-1);
	dad[0] = 0;
	visited[0] = true;
	queue<int> q;
	q.push(0);
	while(q.size() && !visited[m-1]){
		int f = q.front();q.pop();
		for(int i = 0; i < 120;++i){
			if(graph[f][i] != 0 && !visited[i]){
				q.push(i);
				visited[i] = true;
				dad[i] = f;
			}
		}
	}
	if(!visited[m-1])
		return 0;
	int less = 10000000;
	int s = m-1;
	while(dad[s] != s){
		less = min(graph[dad[s]][s],less);
		s = dad[s];
	}
	s = m-1;
	while(dad[s] != s){
		graph[s][dad[s]] += less;
		graph[dad[s]][s] -= less;
		s = dad[s];
	}
	return less;
}

int main(){
	while(1){
		memset(graph,0,sizeof(graph));
		int m,w;
		scanf(" %d %d",&m,&w);
		if(m == 0 && w == 0)
			break;
		for(int i = 1;i < m-1;++i){
			int id,val;
			scanf(" %d %d",&id,&val);
			--id;
			graph[id][id+m] = val;
		}
		for(int i = 0;i < w;++i){
			int j,k,d;
			scanf(" %d %d %d",&j,&k,&d);
			--j;--k;
			if(j == 0){
				graph[j][k] = d;
				if(k == m-1)
					graph[k][j] = d;
				else
					graph[k+m][j] = d;
			}
			else if(k == 0){
				graph[k][j] = d;
				if(j == m-1)
					graph[j][k] = d;
				else
					graph[j+m][k] = d;
			}
			else{
				if(j == m-1){
					graph[j][k] = d;
					graph[k+m][j] = d;
				}
				else if(k == m-1){
					graph[j+m][k] = d;
					graph[k][j+m] = d;
				}
				else{
					graph[j+m][k] = d;
					graph[k+m][j] = d;
				}
			}
		}
		int ans = 0;
		while(1){
			int num = bfs(m);
			//cout << "num is " <<num<< endl;
			if(num == 0)
				break;
			ans += num;
		}
		printf("%d\n",ans);
	}
}