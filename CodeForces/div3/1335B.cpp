#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,a,b;
        scanf(" %d %d %d",&n,&a,&b);
        char ans[n+1];
        ans[n] = '\0';
        for(int i = 0, j = 0, k = 0; i < n;++i){
            if(k == a){
                k = 0;
                j = 0;
            }
            ans[i] = 'a'+j;
            ++k;
            if(j < b-1) ++j;
        }
        printf("%s\n",ans);
    }
    return 0;
}
