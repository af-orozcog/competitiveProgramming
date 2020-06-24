#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        printf("Case #%d: ",cas++);
        int x,y;
        scanf(" %d %d",&x,&y);
        int imp = abs(x)&abs(y);
        int val = __builtin_popcount(imp);
        if(val > 1 || (x%2 == y%2)){
            puts("IMPOSSIBLE"); continue;
        }

    }
}
