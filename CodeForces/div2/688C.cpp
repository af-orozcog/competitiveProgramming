#include<iostream>
#include<vector>
#include<queue>

int BLUE = 0,RED = 1;

using namespace std;

bool bfs(int s,vector<vector<int>> &graph, vector<int> &visi,vector<int> &blue,vector<int> &red){
	visi[s] = RED;
	red.push_back(s);
	queue<int> q;
	q.push(s);
	//cout << "s is" << s<<endl;
	bool posi = true;
	while(q.size() && posi){
		int f = q.front();q.pop();
		for(int i = 0; i < graph[f].size();++i){
			if(visi[graph[f][i]] == -1){
				if(visi[f] == RED){
					visi[graph[f][i]] = BLUE;
					blue.push_back(graph[f][i]);
				}
				else{
					visi[graph[f][i]] = RED;
					red.push_back(graph[f][i]);
				}
				q.push(graph[f][i]);
			}
			if(visi[graph[f][i]] == visi[f])
				posi = false; 
		}
	}
	return posi;
}

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	vector<vector<int>> graph(n);
	for(int i = 0; i < m;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		--a;--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> blue;
	vector<int> red;
	vector<int> dist(n,-1);
	for(int i = 0; i < n;++i){
		if(dist[i] != -1 || graph[i].size() == 0)
			continue;
		if(!bfs(i,graph,dist,blue,red)){
			puts("-1");
			return 0;
		}
	}
	cout <<blue.size()<<endl;
	for(int i = 0; i < blue.size();++i){
		if(i == 0)
			printf("%d",blue[i]+1);
		else
			printf(" %d",blue[i]+1);	
	}
	puts("");
	cout << red.size()<< endl;
	for(int i = 0; i < red.size();++i){
		if(i == 0)
			printf("%d",red[i]+1);
		else
			printf(" %d",red[i]+1);	
	}
	puts("");
	return 0;
}