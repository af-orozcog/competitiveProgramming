#include<iostream>
#include<vector>
#include<cstring>
#define min(x,y)(x < y ? x:y)
#define ll long long

using namespace std;
typedef pair<int,int> pii;

ll dp[1000][1001];
int M,T;
ll cost[1000];
int timee[1000];

ll solve(int i, int t,vector<vector<int>> &graph){
	if(t == M && i == 0)
		return 0;
	if(t >= M)
		return 100000000000;
	ll ans = 100000000000;
	if(dp[i][t] != -1)
		return dp[i][t];
	ans = min(ans,solve(i,t+timee[i],graph) + cost[i]);
	for(int j = 0; j < graph[i].size();++j)
		ans = min(ans,solve(graph[i][j],T+t+timee[graph[i][j]],graph)+cost[graph[i][j]]);
	return dp[i][t] = ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n,m;
	scanf(" %d %d %d %d",&M,&n,&m,&T);
	vector<vector<int>> graph(n);
	for(int i = 0; i < m;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		--a;
		--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 0; i <n;++i)
		scanf(" %d %lld",&timee[i],&cost[i]);
	ll ans = solve(0,timee[0],graph) + cost[0];
	if(ans >= 100000000000)
		puts("It is a trap.");
	else
		printf("%lld\n",ans);
	return 0;
}