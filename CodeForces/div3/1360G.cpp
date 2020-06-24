#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m,a,b;
        scanf(" %d %d %d %d",&n,&m,&a,&b);
        bool posi = 1;
        char ans[n][m+1];
        for(int i = 0; i < n;++i) ans[i][m] = '\0';
        int co = m;
        for(int i = 0,sta = 0,k = 0; i < n && posi;++i){
            int left = a;
            for(int j = 0; j < m;++j){
                if(j >= sta && left){
                    ans[i][j] = '1';
                    --left;
                }
                else ans[i][j] = '0';
            }
            if(left != 0) posi = 0;
            ++k;
            if(k == b){k = 0,sta+=a;co-=a;}
        }
        //cout << co << "\n";
        if(posi && co == 0){
            puts("YES");
            for(int i = 0; i < n;++i)printf("%s\n",ans[i]);
        }
        else puts("NO");
    }
    return 0;
}
