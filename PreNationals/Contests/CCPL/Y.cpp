#include<bits/stdc++.h>
using namespace std;

int movesX[] = {0,0,1,-1};
int movesY[] = {1,-1,0,0};

int n,m;

char matrix[60][60];

int dfs(int x, int y, char let){
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(matrix[x][y] != let) return 0;
    matrix[x][y] = '.';
    int ans = 1;
    for(int i = 0; i < 4;++i)
        ans += dfs(x+movesX[i],y+movesY[i],let);
    return ans;
}

bool comp(const pair<int,char> &a, const pair<int,char> &b){
    if(a.first > b.first) return 1;
    if(b.first > a.first) return 0;
    return a.second < b.second;
}

int main(){
    int cas = 1;
    while(1){
        scanf(" %d %d",&n,&m);
        if(n == 0 && m == n) break;
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m;++j)
                scanf(" %c",&matrix[i][j]);
        }
        vector<pair<int,char>> ans;
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m;++j){
                if(matrix[i][j] != '.'){
                    char let = matrix[i][j];
                    ans.push_back({dfs(i,j,matrix[i][j]),let});
                }
            }
        }
        sort(ans.begin(),ans.end(),comp);
        printf("Problem %d:\n",cas++);
        for(auto va:ans)
            printf("%c %d\n",va.second,va.first);
    }
    return 0;
}
