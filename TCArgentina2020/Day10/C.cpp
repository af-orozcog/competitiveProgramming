#include<bits/stdc++.h>
using namespace std;

int matrix[100][100];

void change(int n, int col){
    for(int i = 0; i < n;++i)
        matrix[i][col] = '@';
}


int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j)
            scanf(" %c",&matrix[i][j]);
    }
    int ans = 0;
    while(1){
        int keep = 0;
        for(int i = 1; i < n && !keep;++i){
            for(int j = 0; j < m && !keep;++j){
                if(matrix[i][j] > matrix[i-1][j])break;
                if(matrix[i][j] < matrix[i-1][j]){
                    keep = 1;
                    change(n,j);
                    ++ans;
                }
            }
        }
        if(!keep)break;
    }
    printf("%d\n",ans);
    return 0;
}
