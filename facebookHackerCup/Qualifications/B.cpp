#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        int coun[2] = {0,0};
        for(int i = 0; i < n;++i){
            char va;
            scanf(" %c",&va);
            ++coun[va-'A'];
        }
        int ma = max(coun[0],coun[1]);
        int mi =min(coun[0],coun[1]);
        printf("Case #%d: ",cas++);
        if(ma-2 == mi-1)
            printf("Y");
        else
            printf("N");
        puts("");
    }
    return 0;
}
