#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,s,k;
        scanf(" %d %d %d",&n,&s,&k);
        int ans = 1000000;
        set<int> no;
        for(int i = 0; i < k;++i){
            int va;scanf(" %d",&va);
            no.insert(va);
        }
        for(int i = 0; i < 1004;++i){
            if(i+s <= n && !no.count(i+s))
                ans = min(ans,i);
            if(s-i > 0 && !no.count(s-i))
                ans = min(ans,i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
