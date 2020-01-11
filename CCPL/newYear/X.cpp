#include<bits/stdc++.h>
using namespace std;

int dp[100][10001];
int energy[100];

int N;

int solve(int p, int s,vector<vector<int>> &graph){
    //cout << "p is" << p << " s is " << s << endl;
    if(s <= 0) return 0;
    if(p == N-1) return 1;
    if(s > 10000) return 0;
    if(dp[p][s] != -1) return dp[p][s];
    int ans = 0;
    for(int i = 0; i < graph[p].size() && !ans;++i)
        ans = ans | solve(graph[p][i],s+energy[p],graph);
    return dp[p][s] = ans;
}

int main(){
    while(scanf(" %d",&N) == 1 && N != -1){
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> graph(N);
        for(int i = 0; i < N;++i){
            scanf(" %d",&energy[i]);
            int n; scanf(" %d",&n);
            for(int j = 0; j < n;++j){
                int va;scanf(" %d",&va);--va;
                graph[i].push_back(va);
            }
        }
        if(solve(0,100,graph)) puts("winnable");
        else puts("hopeless");
    }
    return 0;
}
