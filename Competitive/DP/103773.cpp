#include<iostream>
#include<vector>

using namespace std;

int vals[10][1000];

void set(int pos,vector<vector<pair<int,int>>> &graph){
	int dig = pos % 10;
	int de = pos / 10;
	if(de*10 == graph.size()-10)
	    return;
	if(dig == 0){
		graph[pos].push_back(make_pair(pos+11,60-vals[dig][de]));
		graph[pos].push_back(make_pair(pos+10,30-vals[dig][de]));
	}
	else if(dig == 9){
		graph[pos].push_back(make_pair(pos+9,20-vals[dig][de]));
		graph[pos].push_back(make_pair(pos+10,30-vals[dig][de]));
	}
	else{
		graph[pos].push_back(make_pair(pos+11,60-vals[dig][de]));
		graph[pos].push_back(make_pair(pos+10,30-vals[dig][de]));
		graph[pos].push_back(make_pair(pos+9,20-vals[dig][de]));
	}
}

vector<int> topo;

void topoSort(int s,vector<vector<pair<int,int>>> &graph,vector<bool> &visi){
	visi[s] = true;
	for(int i = 0; i < graph[s].size();++i){
	    int w = graph[s][i].first;
		if(!visi[graph[s][i].first])
			topoSort(graph[s][i].first,graph,visi);
	}
	topo.push_back(s);
}

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		topo.clear();
		int n;
		scanf(" %d",&n);
		n /= 100;
		for(int i = 9; i >= 0;--i){
			for(int j = 0; j < n;++j)
				scanf(" %d",&vals[i][j]);
		}
		vector<vector<pair<int,int>>> graph(10*(n+1));
		for(int i = 0; (i*10) < 10*n;++i){
			for(int j = 0; j < 10;++j)
				set(i*10 + j,graph);
		}
		vector<bool> visi(graph.size(),false);
		topoSort(0,graph,visi);
		vector<int> dist(graph.size(),1000000000);
		dist[0] = 0;
		/*for(int i = 0; i < graph[31].size();++i){
		    cout << graph[31][i].first << " "<< graph[31][i].second<<endl;
		}*/
		for(int i = topo.size() -1; i >= 0;--i){
		    int f = topo[i];
			for(int j = 0; j < graph[f].size();++j){
			    int vv = graph[f][j].first;
			    int uu = dist[f];
			    int ww = graph[f][j].second;
			    int qq = dist[graph[f][j].first];
				if(dist[f] + graph[f][j].second < dist[graph[f][j].first]){
					dist[graph[f][j].first] = dist[f] + graph[f][j].second;
				}
			}
		}
		printf("%d\n",dist[10*(n)]);
		puts("");
	}
	return 0;
}