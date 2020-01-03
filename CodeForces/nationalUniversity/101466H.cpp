#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    char ans[n][(n<<1)+1];
    for(int i = 0; i < n;++i){
        for(int j = 0; j < (n<<1)+1;++j) ans[i][j] = ' ';
    }
    for(int i = 0; i < n;++i)
        ans[i][0] = ans[i][n-1] = ans[i][n+1] = ans[i][n<<1] = '*';
    for(int i = 0; i < n;++i)
        ans[n-1][i] = '*';
    for(int i = n+1; i < (n<<1)+1;++i)
        ans[0][i] = '*';
    for(int i = 0; i < n;++i){
        for(int j = 0; j < (n<<1)+1;++j)
            printf("%c",ans[i][j]);
        puts("");
    }
}
