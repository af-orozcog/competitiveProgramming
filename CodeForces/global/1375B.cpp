#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        int matrix[n][m];
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m;++j)
                scanf(" %d",&matrix[i][j]);
        }
        int posi = 1;
        for(int i = 0; i < n && posi;++i){
            for(int j = 0; j < m && posi;++j){
                if(i == 0 && j == 0 || i == 0 && j == m-1
                || i == n-1 && j == 0 || i == n-1 && j == m-1){
                    if(matrix[i][j] > 2) posi = 0;
                    matrix[i][j] = 2;
                }
                else if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(matrix[i][j] > 3) posi = 0;
                    matrix[i][j] = 3;
                }
                else{
                    if(matrix[i][j] > 4) posi = 0;
                    matrix[i][j] = 4;
                }
            }
        }
        if(posi){
            puts("YES");
            for(int i = 0; i < n;++i){
                for(int j = 0; j < m;++j)
                    printf("%d ",matrix[i][j]);
                puts("");
            }
        }
        else puts("NO");
    }
    return 0;
}
