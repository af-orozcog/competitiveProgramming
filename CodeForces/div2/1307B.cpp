#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,x;
        scanf(" %d %d",&n,&x);
        int ans = 2000000000;
        for(int i = 0; i < n;++i){
            int va;scanf(" %d",&va);
            if(va > x) ans = min(ans,2);
            else ans = min(ans,x/va +(x%va != 0));
        }
        printf("%d\n",ans);
    }
    return 0;
}
