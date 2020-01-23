#include<bits/stdc++.h>

using namespace std;

int matrix[2][100000];

int main(){
    int n,q;
    scanf(" %d %d",&n,&q);
    int blocked;
    set<pair<int,int>> col;
    while(q--){
        int r,c;
        scanf(" %d %d",&r,&c);
        --r,--c;
        matrix[r][c] = (matrix[r][c]+1)&1;
        if(matrix[r][c]){
            for(int i = max(c-1,0); i <= min(c+1,n-1);++i){
                if(matrix[(r+1)&1][i]) col.insert({min(i,c),max(i,c)});
            }
        }
        else{
            col.erase({c,c});
            for(int i = max(c-1,0); i <= min(c+1,n-1);++i){
                if(i == c) continue;
                if(matrix[r][i] != matrix[(r+1)&1][c]  || !(matrix[r][i] & matrix[(r+1)&1][c]))
                    col.erase({min(i,c),max(i,c)});
            }
        }
        if(!col.size()) puts("Yes");
        else puts("No");
    }
    return 0;
}
