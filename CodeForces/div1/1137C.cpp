#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#define max(x,y)(x > y?x:y)

using namespace std;

vector<vector<int>> graph(100000);
string mus[100000];
int dp[50][100000];
int D;
bool visi[100000];

int solve(int d,int c){
	if(dp[d][c] != -1)
		return dp[d][c];
	int ans = mus[c][d] == '1'?1:0;
	if(visi[c])
		ans = 0;
	if(ans)
		visi[c] =true;
	int sum = 0;
	for(int i = 0; i< graph[c].size();++i){
		sum = max(sum,solve((d+1)%D,graph[c][i]));
	}
	visi[c] = false;
	return dp[d][c] = sum+ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	memset(visi,sizeof(visi),false);
	int n,m;
	scanf(" %d %d %d",&n,&m,&D);
	for(int i = 0; i < m;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		--a;--b;
		graph[a].push_back(b);
	}
	for(int i= 0;i < n;++i)
		cin >> mus[i];
	cout << solve(0,0) << endl;
}