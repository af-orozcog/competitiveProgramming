#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        vector<int> ar(101,0);
        vector<int> mod(2,0);
        for(int i = 0; i < n;++i){
            int va;
            scanf(" %d",&va);
            ++mod[(va&1)];
            ++ar[va];
        }
        if(mod[0]%2 == mod[1]%2){
            //puts("etf");
            if(mod[0]%2 == 0) puts("YES");
            else{
                bool see = 0;
                for(int i = 1; i < 101;++i){
                    if(ar[i-1] && ar[i]){
                        puts("YES");
                        see = 1;
                        break;
                    }
                }
                if(!see)puts("NO");
            }
        }
        else puts("NO");
    }
    return 0;
}
