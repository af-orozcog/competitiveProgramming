#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int last = -1000;
        int n;
        bool posi = 1;
        scanf(" %d",&n);
        for(int i = 0; i < n;++i){
            int va;
            scanf(" %d",&va);
            if(va == 1){
                if(i - last < 6) posi = 0;
                last = i;
            }
        }
        if(posi)puts("YES");
        else puts("NO");
    }
    return 0;
}
