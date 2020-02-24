#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

int matrix[1000][1000],sub[1000][1000];

int movesX[] = {0,0,1,-1};
int movesY[] = {1,-1,0,0};
int n,m;

int bfs(int x,int y){
    queue<pi> q;
    q.push({x,y});
    matrix[x][y] = 0;
    int ma = 0; pi who;
    while(q.size()){
        pi f = q.front();q.pop();
        for(int i = 0; i < 4;++i){
            pi to = {f.first+movesX[i],f.second+movesY[i]};
            if(to.first == n || to.second == m || to.first < 0 || to.second < 0) continue;
            if(matrix[to.first][to.second] != -1 ||
               sub[to.first][to.second] != 1) continue;
            matrix[to.first][to.second] = matrix[f.first][f.second] + 1;
            q.push({to.first,to.second});
            if(matrix[to.first][to.second] > ma) who = to,ma = matrix[to.first][to.second];
        }
    }
    int matrix2[n][m];
    memset(matrix2,-1,sizeof(matrix2));
    ma = 0;
    q.push(who);
    matrix2[who.first][who.second] = 0;
    while(q.size()){
        pi f = q.front();q.pop();
        for(int i = 0; i < 4;++i){
            pi to = {f.first+movesX[i],f.second+movesY[i]};
            if(to.first == n || to.second == m || to.first < 0 || to.second < 0) continue;
            if(matrix2[to.first][to.second] != -1 ||
               sub[to.first][to.second] != 1) continue;
            matrix2[to.first][to.second] = matrix2[f.first][f.second] + 1;
            q.push({to.first,to.second});
            if(matrix2[to.first][to.second] > ma) ma = matrix2[to.first][to.second];
        }
    }
    return ma;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        scanf(" %d %d",&m,&n);
        for(int i = 0; i < n;++i)
            for(int j = 0; j < m;++j)
                matrix[i][j] = -1;
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m;++j){
                char va;scanf(" %c",&va);
                if(va == '.') sub[i][j] = 1;
                else sub[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m;++j){
                //cout << sub[i][j] << " " << matrix[i][j] << endl;
                if(sub[i][j] == 0 || matrix[i][j] != -1) continue;
                ans = max(bfs(i,j),ans);
            }
        }
        printf("Maximum rope length is %d.\n",ans);
    }
    return 0;
}
