#include<iostream>
#include<vector>
#define ll long long
#include<cstring>

using namespace std;

int main(){
	int n,m,k;
	cin >> n >>m >>k;
	vector<vector<pair<int,ll>>> graph(n);
	for(int i = 0; i < m;++i){
		int a,b;
		ll l;
		cin >> a >> b >> l;
		--a;--b;
		graph[a].push_back(make_pair(b,l));
		graph[b].push_back(make_pair(a,l));
	}
	bool marked[graph.size()];
	memset(marked,false,sizeof(marked));
	vector<int> mar(k);
	for(int i = 0; i < k;++i){
		cin >> mar[i];
		--mar[i];
		marked[mar[i]]=true;
	}
	ll min = 10000000000;
	for(int i = 0; i < k;++i){
		int in = mar[i];
		for(int j = 0;j < (int)graph[in].size();++j){
			if(!marked[graph[in][j].first]){
				if(graph[in][j].second < min)
					min = graph[in][j].second;
			}
		}
	}
	if(min == 10000000000)
		min = -1;
	cout << min << endl;
	return 0;
}