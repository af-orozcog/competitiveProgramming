#include<iostream>
#include<queue>
#include<vector>

using namespace std;

pair<int,int> opponents[12];
pair<int,int> team[12];
int N;
 
bool possible(int l, int m){
	pair<int,int> coor1 = team[l];
	pair<int,int> coor2 = team[m];
	for(int i = 0; i < N;++i){
		if(opponents[i].first >= min(coor1.first,coor2.first) && opponents[i].first <= max(coor1.first,coor2.first) && opponents[i].second >=min(coor1.second,coor2.second) && opponents[i].second <= max(coor1.second,coor2.second)){
			pair<int,int> m1 = {coor1.second-opponents[i].second,coor1.first - opponents[i].first};
			pair<int,int> m2 = {coor2.second-opponents[i].second,coor2.first-opponents[i].first};
			if(m2.second == m1.second && m2.second == 0)
				return false;
			if(m2.first == m1.first && m2.first == 0)
				return false;
			int check;
			check = m1.first*m2.second - m2.first*m1.second;
			if(check == 0)
				return false;
		}
		if( i != l && i != m && team[i].first >= min(coor1.first,coor2.first) && team[i].first <= max(coor1.first,coor2.first) && team[i].second >=min(coor1.second,coor2.second) && team[i].second <= max(coor1.second,coor2.second)){
			pair<int,int> m1 = {coor1.second-team[i].second,coor1.first - team[i].first};
			pair<int,int> m2 = {coor2.second-team[i].second,coor2.first-team[i].first};
			if(m2.second == m1.second && m2.second == 0)
				return false;
			if(m2.first == m1.first && m2.first == 0)
				return false;
			int check;
			check = m1.first*m2.second - m2.first*m1.second;
			if(check == 0)
				return false;
		}
	}
	return true;
}

int main(){
	scanf(" %d",&N);
	for(int i = 0; i < N;++i)
		scanf(" %d %d",&team[i].first,&team[i].second);
	for(int i = 0; i < N;++i)
		scanf(" %d %d",&opponents[i].first,&opponents[i].second);
	vector<vector<int>> graph(N);
	for(int i = 0; i < N;++i){
		for(int j = i+1; j < N;++j){
			if(possible(i,j)){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	vector<int> dist(N,-1);
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while(q.size()){
		int f = q.front();q.pop();
		for(int i = 0; i < graph[f].size();++i){
			if(dist[graph[f][i]] == -1){
				dist[graph[f][i]] = dist[f] +1;
				q.push(graph[f][i]);
			}
		}
	}
	printf("%d\n",dist[N-1]);
	return 0;
}