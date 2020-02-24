#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

int main(){
    while(1){
        int n,m; scanf(" %d",&n);
        if(!n)break;
        scanf(" %d",&m);
        double matrix[n][n];
        for(int i = 0; i < n;++i){
            for(int j = 0;j < n;++j) matrix[i][j] = 0;
            matrix[i][i] = 1;
        }
        for(int i = 0; i < m;++i){
            int a,b,c;
            scanf(" %d %d %d",&a,&b,&c);
            --a,--b;
            matrix[a][b] = matrix[b][a] = (double)c/100.0;
        }
        for(int k = 0; k < n;++k){
            for(int i = 0; i < n;++i){
                for(int j = 0; j < n;++j)
                    matrix[i][j] = max(matrix[i][j],matrix[i][k]*matrix[k][j]);
            }
        }
        double ans = (matrix[0][n-1]);
        printf("%.6f percent\n",ans*100.0);
    }
    return 0;
}
