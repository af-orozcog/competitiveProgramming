/**
* I only hope everything will be back to normal
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

vector<int> ans;
bool dfs(int from, vector<vector<int>>&graph,vector<int> &level,int co){
	level[from] = co;
	bool posi = 1;
	for(int i = 0; i < graph[from].size() && posi;++i){
		if(level[graph[from][i]] == -1)
			dfs(graph[from][i],graph,level,co+1);
		else if(level[graph[from][i]] < co)
			posi = 0;
	}
	ans.push_back(from);
	return posi;
}

int main(){
	int to[5];
	memset(to,0,sizeof(to));
	vector<vector<int>> graph(5);
	for(int i = 0; i < 5;++i){
		string re;cin >> re;
		if(re[1] == '>'){
			graph[re[0]-'A'].push_back(re[2]-'A');
			++to[re[2]-'A'];
		}
		else{
			graph[re[2]-'A'].push_back(re[0]-'A');
			++to[re[0]-'A'];
		}
	}
	vector<int> level(5,-1);
	bool posi = 0;
	for(int i = 0; i < 5;++i){
		if(!to[i]){
			level[i] = 0;
			posi = 1;
			break;
		}
	}
	if(!posi){
		puts("impossible");
		return 0;
	}
	vector<int> show;
	for(int i = 0; i < 5 && posi;++i){
		if(level[i] == 0){
			posi = dfs(i,graph,level,0);
			for(int i = ans.size()-1; i >= 0;--i)
				show.push_back(ans[i]);
			break;
		}
	}
	if(show.size()!= 5){
		puts("impossible");
		return 0;
	}
	for(int i = 0; i < 5;++i){
		char s = 'A'+show[i];
		cout << s;
	}
	puts("");
	return 0;	
}