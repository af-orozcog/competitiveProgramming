#include<bits/stdc++.h>
using namespace std;

int matrix[3][100][100];

int movesX[] = {0,0,1,-1};
int movesY[] = {1,-1,0,0};
int n,m;

void bfs(int po1,int po2,int who){
    queue<pair<int,int>> q;
    q.push({po1,po2});
    matrix[who][po1][po2] = 0;
    while(q.size()){
        pair<int,int> da = q.front();q.pop();
        for(int i = 0; i < 4;++i){
            int toX = da.first + movesX[i], toY = da.second + movesY[i];
            int dist = matrix[who][da.first][da.second] + 1;
            if(toX < 0 || toX == n || toY < 0 || toY == m) continue;
            if(matrix[who][toX][toY] != -1) continue;
            if(who == 2 && (dist >= matrix[0][toX][toY] || dist >= matrix[1][toX][toY])) continue;
            matrix[who][toX][toY] = dist;
            q.push({toX,toY});
        }
    }
}

int main(){
    scanf(" %d %d",&n,&m);
    int t;
    scanf(" %d",&t);
    while(t--){
        memset(matrix,-1,sizeof(matrix));
        int m1,m2,c1,c2,c3,c4;
        scanf(" %d %d %d %d %d %d",&m1,&m2,&c1,&c2,&c3,&c4);
        --m1,--m2,--c1,--c2,--c3,--c4;
        if(m1 == c1 && m2 == c2){puts("NO");continue;}
        if(m1 == c3 && m2 == c4){puts("NO");continue;}
        bfs(c1,c2,0);
        bfs(c3,c4,1);
        bfs(m1,m2,2);
        int ans = 0;
        for(int i = 0; i < m && !ans;++i)
            if(matrix[2][0][i] != -1 || matrix[2][n-1][i] != -1) ans = 1;
        for(int i = 0; i < n && !ans;++i)
            if(matrix[2][i][0] != -1 || matrix[2][i][m-1] != -1) ans = 1;
        if(ans) puts("YES");
        else puts("NO");
    }
}
