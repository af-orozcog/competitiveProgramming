#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        int matrix[n][n];
        for(int i = 0; i < n;++i)
            for(int j = 0; j < n;++j) scanf(" %d",&matrix[i][j]);
        int trace = 0;
        for(int i = 0; i < n;++i)
            trace += matrix[i][i];
        int row = 0;
        int cop[n];
        set<int> seen;
        for(int i = 0; i < n;++i){
            for(int j = 0; j < n ;++j) seen.insert(matrix[i][j]);
            if((int)seen.size() != n) ++row;
            seen.clear();
        }
        int col = 0;
        for(int j = 0; j < n;++j){
            for(int i = 0; i < n;++i) seen.insert(matrix[i][j]);
            if((int)seen.size() != n) ++col;
            seen.clear();
        }
        printf("Case #%d: %d %d %d\n",cas++,trace,row,col);
    }
    return 0;
}
