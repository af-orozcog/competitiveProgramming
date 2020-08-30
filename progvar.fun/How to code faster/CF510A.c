#include<stdio.h>

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    char matrix[n][m];
    for(int i = 0; i < n;++i)
        for(int j = 0; j < m;++j)
            matrix[i][j] = '.';
    for(int i = 0; i < n;i+=2)
        for(int j = 0; j < m;++j)
            matrix[i][j] = '#';
    for(int i = 1, j = m - 1; i < n;i+=2){
        matrix[i][j] = '#';
        if(j == m-1) j = 0;
        else j = m - 1;
    }
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j)
            printf("%c",matrix[i][j]);
        puts("");
    }
    return 0;
}
