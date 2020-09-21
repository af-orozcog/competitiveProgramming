#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;


int movesX[] = {0,0,1,-1,1,1,-1,-1};
int movesY[] = {1,-1,0,0,-1,1,1,-1};
int dp[501][501];

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    int matrix[n][m];
    for(int i = 0; i < n;++i)
        for(int j = 0; j < m;++j)
            scanf(" %d",&matrix[i][j]);
    int x,y;
    scanf(" %d %d",&x,&y);
    ll ans = 0;
    --x,--y;
    priority_queue<pair<int,pi>> q;
    q.push({-matrix[x][y],{x,y}});
    dp[x][y] = matrix[x][y];
    while(q.size()){
        pi dad = {q.top().second.first,q.top().second.second}; int val = -q.top().first;
        q.pop();
        if(dp[dad.first][dad.second] < val)continue;
        int nePos = max(val,matrix[dad.first][dad.second]);
        for(int i = 0; i < 8;++i){
            pi ne = {dad.first+movesX[i],dad.second+movesY[i]};
            if(ne.first < 0 || ne.first >= n || ne.second < 0 || ne.second >= m) continue;
            if(matrix[ne.first][ne.second] >= 0) continue;
            if(dp[ne.first][ne.second] <= nePos) continue;
            dp[ne.first][ne.second] = nePos;
            q.push({-nePos,{ne.first,ne.second}});
        }
    }
    for(int i = 0; i < n;++i)
        for(int j = 0; j < m;++j){
            if(matrix[i][j] > 0) continue;
            ans += (ll)(max(dp[i][j],matrix[i][j])*-1);
        }
    printf("%lld\n",ans);
    return 0;
}
