#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    char matrix[n][n];
    for(int i = 0; i < n;++i){
        for(int j = 0; j < n;++j)
            scanf(" %c",&matrix[i][j]);
    }
    bool posi = 1;
    for(int i = 0; i < n && posi;++i){
        int black = 0, white = 0;
        for(int j = 0; j < n && posi;++j){
            if(matrix[i][j] == 'B')++black;
            if(matrix[i][j] == 'W') ++white;
            if(j > 2 && matrix[i][j-1] == matrix[i][j-2] && matrix[i][j-1] == matrix[i][j]) posi = 0;
        }
        if(black != white) posi = 0;
    }
    for(int i = 0; i < n && posi;++i){
        int black = 0, white = 0;
        for(int j = 0; j < n && posi;++j){
            if(matrix[j][i] == 'B')++black;
            if(matrix[j][i] == 'W') ++white;
            if(j > 2 && matrix[j-1][i] == matrix[j-2][i] && matrix[j-1][i] == matrix[j][i]) posi = 0;
        }
        if(black != white) posi = 0;
    }
    if(posi) puts("1");
    else puts("0");
    return 0;
}
