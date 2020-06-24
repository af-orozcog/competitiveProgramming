#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        char ar[n][n];
        for(int i = 0; i < n;++i)
            for(int j = 0; j < n;++j)
                scanf(" %c",&ar[i][j]);
        int posi = 1;
        for(int i = n-2; i > -1 && posi;--i){
            for(int j = n-2; j > -1 && posi;--j){
                if(ar[i][j] == '1'){
                    if(ar[i][j+1] != '1' && ar[i+1][j] != '1')
                        posi = 0;
                }
            }
        }
        if(posi) puts("YES");
        else puts("NO");
    }
    return 0;
}
