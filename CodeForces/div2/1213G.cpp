#include<iostream>
#include<vector>
#include<algorithms>
#define ll long long

using namespace std;

int UF[200000];
int rk[200000];

void sett(int n){
	for(int i = 0;i < n;++i){
		UF[i] = i;
		rk[i] = 0;
	}
}

int search(int x){
	return UF[x] == x ? x : (UF[x] = search(UF[x]));
}

bool connected(int x, int y){
	return search(x) == search(y);
}

void connect(int x, int y){
	int dadX = search(x), dadY = search(y);
	if(dadX != dadY){
		UF[dadX] = UF[dadY];
		rk[dadY] += rk[dadX];
	}
}

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	vector<pair<int,pair<int,int>>> graph(n-1);
	for(int i = 0; i < n-1;++i){
		int a,b,c;
		scanf(" %d %d %d",&a,&b,&c);
		--a;--b;
		graph[i] = {c,{a,b}};
	}
	sort(graph.begin(),graph.end());
	vector<pair<int,int>> que(m);
	for(int i = 0; i < m;++i){
		int va;scanf(" %d",&va);
		que[i] = {va,i};
	}
	sort(que.begin(),que.end());
	vector<ll> ans(m);
	ll ans = 0;
	int po = 0;
	for(auto &va:que){
		int m = va.first;
		while(po < graph.size() && graph[po].first <= m){
			int a = graph[po].second.first, b = graph[po].second.second;
			ans -= rk[a];
			ans -= rk[b];
			connect(a,b);
			ans += (((ll)rk*((ll)rk+1))>>1);
			++po;
		}
		ans[va.second] = ans;
	}
	for(auto &va:ans)
		cout << va << " ";
	puts("");
	return 0;
}