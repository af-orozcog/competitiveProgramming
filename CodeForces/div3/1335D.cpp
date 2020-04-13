#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int matrix[9][9];
        for(int i = 0; i < 9;++i){
            for(int j = 0; j < 9;++j){
                char temp; scanf(" %c",&temp);
                matrix[i][j] = temp-'0';
            }
        }
        set<int> ava;
        set<int> rep;
        for(int i = 1; i <= 9;++i) ava.insert(i);
        for(int i = 0, j = 0; i < 9;++i,j+=3){
            if(i == 3) j = 1;
            if(i == 6) j = 2;
        }
        for(int i = 0; i < 9;++i){
            for(int j = 0; j < 9;++j)printf("%d",matrix[i][j]);
            puts("");
        }
    }
    return 0;
}
