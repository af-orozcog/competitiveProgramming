#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int UF[200000];
int rk[200000];

void sett(int n){
	for(int i = 0; i < n;++i){
		UF[i] = i;
		rk[i] = 1;
	}
}

int search(int x){
	return UF[x] == x ? x: (UF[x] = search(UF[x]));
}

bool connected(int x, int y){
	return search(x) == search(y);
}

void connect(int x, int y){
	int dadX = search(x),dadY = search(y);
	if(dadX != dadY){
		if(rk[dadX] > rk[dadY]){
			UF[dadY] = dadX;
		}
		else{
			UF[dadX] = dadY;
			if(rk[dadY] == rk[dadX]) ++rk[dadY];
		}
	}
}
int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	sett(n);
	vector<vector<int>> graph(n);
	vector<pair<int,int>> num(n,make_pair(0,-1));
	for(int i = 0; i < m;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		--a;--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		num[a].second = a;
		++num[a].first;
		num[b].second = b;
		++num[b].first;
	}
	sort(num.begin(),num.end());
	vector<pair<int,int>> edges;
	for(int i = n-1; i >= 0;--i){
		int f = num[i].second;
		for(int j = 0; j < (int)graph[f].size();++j){
			int b = graph[f][j];
			if(!connected(f,b)){
				edges.push_back(make_pair(f,b));
				connect(f,b);
			}
		}
	}
	for(int i = 0; i < edges.size();++i)
		printf("%d %d\n",edges[i].first+1,edges[i].second+1);
	return 0;
}