#include<bits/stdc++.h>
using namespace std;

int n,m;
int movesX[] = {0,0,1,-1,1,1,-1,-1};
int movesY[] = {1,-1,0,0,1,-1,1,-1};

int neigh(int x, int y,vector<vector<char>> &matrix){
    int ans = 0;
    for(int i = 0; i < 8;++i){
        int neX = x + movesX[i], neY = y + movesY[i];
        if(neX < 0 || neX >= n || neY < 0 || neY >= m) continue;
        if(matrix[neX][neY] == '*') ++ans;
    }
    return ans;
}


int main(){
    int t = 1;
    while(scanf(" %d %d",&n,&m) && n){
        if(t != 1) puts("");
        vector<vector<char>> matrix(n,vector<char>(m));
        for(int i = 0; i < n;++i)
            for(int j = 0; j < m;++j)
                scanf(" %c",&matrix[i][j]);
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m;++j){
                if(matrix[i][j] != '*')
                    matrix[i][j] = '0' + neigh(i,j,matrix);
            }
        }
        printf("Field #%d:\n",t++);
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m;++j)
                printf("%c",matrix[i][j]);
            puts("");
        }
    }
    return 0;
}
