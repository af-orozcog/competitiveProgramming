#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int big = n;
        set<int> seen;
        int who = -1;
        for(int i = 0; i < n;++i){
            int k; scanf(" %d",&k);
            bool cha = 0;
            for(int j = 0; j < k;++j){
                int va;scanf(" %d",&va);
                if(!seen.count(va) && !cha){
                    seen.insert(va);
                    cha = 1;
                }
            }
            if(!cha) who = i+1;
            while(seen.count(big))
                --big;
        }
        if(who == -1) puts("OPTIMAL");
        else printf("IMPROVE\n%d %d\n",who,big);
    }
    return 0;
}
