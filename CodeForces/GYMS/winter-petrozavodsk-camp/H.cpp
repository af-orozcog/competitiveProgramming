#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n,m;
    scanf(" %d %d",&n,&m);
    int used = 0;
    for(int j = 1; j < n && m;++j){
        for(int i = 0; i < n-j && m;++i){
            printf("%d %d %d\n",i+1,i+j+1,j-1);
            --m;
        }
    }
    return 0;
}
