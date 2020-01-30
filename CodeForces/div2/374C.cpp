#include<bits/stdc++.h>
using namespace std;

int visited[1000][1000],loop = 1;
char matrix[1000][1000];
int dp[1000][1000];
int N,M;
bool cycle = 0;
char di[] = {'D','I','M','A'};

int movesX[] = {0,0,1,-1}, movesY[] = {1,-1,0,0};

int dfs(int p, int q, int pf, int qf, int who,set<pair<int,int>> &seen){
    if(p < 0 || p == N || q < 0 || q == M) return 0;
    if(matrix[p][q] != di[who]) return 0;
    if(visited[p][q] == loop && seen.count({p,q})){cycle = 1;return 0;}
    if(dp[p][q] != -1) return dp[p][q];
    visited[p][q] = loop;
    seen.insert({p,q});
    dp[p][q] = (who == 3? 1:0);
    int temp = 0;
    for(int i = 0; i < 4;++i){
        int toP = movesX[i] + p, toQ = movesY[i] + q;
        if(toP == pf && toQ == qf) continue;
        temp = max(temp,dfs(toP,toQ,p,q,(who+1)%4,seen));
        seen.erase({toP,toQ});
        if(cycle) return 0;
    }
    dp[p][q] += temp;
    return dp[p][q];
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf(" %d %d",&N,&M);
    for(int i = 0; i < N;++i){
        for(int j = 0; j < M;++j) scanf(" %c",&matrix[i][j]);
    }
    int ans = 0;
    set<pair<int,int>> seen;
    for(int i = 0; i < N && ans != -1;++i){
        for(int j = 0; j < M && ans != -1;++j){
            if(!visited[i][j] && matrix[i][j] == 'D'){
                int temp = dfs(i,j,-1,-1,0,seen);
                seen.erase({i,j});
                ans = max(ans,temp);
                ++loop;
            }
            else continue;
            if(cycle)ans = -1;
        }
    }
    if(ans == -1) puts("Poor Inna!");
    else if(!ans) puts("Poor Dima!");
    else printf("%d\n",ans);
    return 0;
}
