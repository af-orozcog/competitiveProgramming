#include<bits/stdc++.h>
using namespace std;

bool ans;

int solve(){
    int wl,dl,wr,dr;
    scanf(" %d %d %d %d",&wl,&dl,&wr,&dr);
    if(wl == 0) wl = solve();
    if(wr == 0) wr = solve();
    ans = ans & (wl*dl == wr*dr);
    return wl+wr;
}


int main(){
    int t;
    scanf(" %d",&t);
    int fi = 0;
    while(t--){
        if(fi)puts("");
        fi = 1;
        ans = 1;
        solve();
        if(ans) puts("YES");
        else puts("NO");
    }
    return 0;
}
