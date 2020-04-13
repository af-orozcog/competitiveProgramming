#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        unordered_map<int,int> fr;
        int n;
        scanf(" %d",&n);
        int ar[n];
        for(int i = 0; i < n;++i){
            scanf(" %d",&ar[i]);
            fr[ar[i]] = i;
        }
        bool ans = 0;
        for(int i = 0; i < n && !ans;++i){
            int see = fr[ar[i]];
            if(see > i + 1) ans = !ans;
        }
        if(ans) puts("YES");
        else puts("NO");
    }
    return 0;
}
