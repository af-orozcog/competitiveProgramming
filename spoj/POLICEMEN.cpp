#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

bool bfs(int a, int b, vector<vector<int>> &graph){
	vector<int> marked1(graph.size(),-1);
	vector<int> marked2(graph.size(),-1);
	vector<int> p1(graph.size());
	p1[a] = a;
	queue<int> q;
	q.push(a);
	marked1[a] = 0;
	while(q.size()){
		int f = q.front();q.pop();
		if(f == 0){
			break;
		}
		for(int i = 0; i < (int)graph[f].size();++i){
			if(marked1[graph[f][i]] == -1){
				marked1[graph[f][i]] = marked1[f] + 1;
				p1[graph[f][i]] = f;
				q.push(graph[f][i]);
			}
		}
	}
	queue<int> w;
	q = w;
	vector<bool> check(graph.size(),false);
	int m = 0;
	check[m] = true;
	while(p1[m] != m){
		check[p1[m]] = true;
		m = p1[m];
	}
	q.push(b);
	marked2[b] = 0;
	if(check[b] && marked1[b] >= marked2[b]){
		cout << "YES " << b + 1 << endl; 
		return true;
	}
	while(q.size()){
		int f = q.front();q.pop();
		if(f == 0){
			break;
		}
		for(int i = 0; i < (int)graph[f].size();++i){
			if(marked2[graph[f][i]] == -1){
				marked2[graph[f][i]] = marked2[f] + 1;
				q.push(graph[f][i]);
				if(check[graph[f][i]]&& marked1[graph[f][i]] >= marked2[graph[f][i]]){
					cout << "YES " << graph[f][i] + 1 << endl; 
					return true;
				}
			}
		}
	}
	return false;
}

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
	int q;
	cin >> q;
	while(q--){
		int a,b;
		cin >> a >> b;
		--a;--b;
		if(a == b){
			cout << "YES " << a+1 << endl;
			continue;
		}
		else{
			if(!bfs(a,b,graph))
				cout << "NO" << endl;
		}
	}
	return 0;
}