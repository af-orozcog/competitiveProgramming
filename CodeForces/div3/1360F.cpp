#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        char ar[n][m];
        vector<set<char>> posi(m);
        for(int i = 0; i < n;++i)
            for(int j = 0; j < m;++j){
                scanf(" %c",&ar[i][j]);
                posi[j].insert(ar[i][j]);
            }
        char ans[m+1];
        ans[m] = '\0';
        for(int i = 0; i < m;++i) ans[i] = ar[0][i];
        bool fi = 0;
        for(int k = 0; k < m && !fi;++k){
            for(auto va:posi[k]){
                ans[k] = va;
                fi = 1;
                for(int i = 0; i < n;++i){
                    int dif = 0;
                    for(int j = 0; j < m;++j)
                        dif += (ans[j]!=ar[i][j]);
                    if(dif > 1) {fi = 0;break;}
                }
                if(fi)break;
            }
            if(!fi)
                ans[k] = ar[0][k];
        }
        if(fi)
            printf("%s\n",ans);
        else puts("-1");
    }
}
