/**
* worried about TLE
*/
#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for(int i = 0; i < n-1;++i){
		int a,b;
		cin >> a >> b;
		--a;--b;
		graph[a].push_back(b);
		graph[b].push_back(a); 
	}
	vector<int> dist(n,-1);
	vector<int> pa(n,-1);
	pa[0] = 0;
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	map<int,int> coun;
	map<int,int> child;
	while(q.size()){
		int f = q.front();q.pop();
		for(int i = 0; i < (int)graph[f].size();++i){
			if(dist[graph[f][i]] == -1){
				if(child.count(f))
					++child[f];
				else
					child[f] = 1;
				dist[graph[f][i]] = dist[f] + 1;
				if(coun.count(dist[graph[f][i]]))
					++coun[dist[graph[f][i]]];
				else
					coun[dist[graph[f][i]]] = 1;
				pa[graph[f][i]] = f;
				q.push(graph[f][i]);
			}
		}
	}
	//cout << "child of 0 " << child[0] << endl;
	vector<int> num(n);
	for(int i = 0; i < n;++i){
		cin >> num[i];
		--num[i];
	}
	bool posi = true;
	int dad = 0;
	int d = 1;
	if(num[0] != 0)
		posi = false;
	for(int i = 1;i <n && posi;++i){
		if(dist[num[i]] != d)
			posi = false;
		else{
			--coun[d];
			if(coun[d] == 0)
				++d;
		}
		while(child.count(num[dad]) == 0){
			++dad;
		}
		if(pa[num[i]] != num[dad]){
			posi = false;
		}
		else{
			--child[num[dad]];
			if(child[num[dad]] == 0)
				++dad;
		}
	}
	if(posi)
		puts("YES");
	else
		puts("NO");
}