#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        set<int> dif;
        for(int i = 0; i < n;++i){
            int va;
            scanf(" %d",&va);
            dif.insert(va);
        }
        if((int)dif.size() > k){
            puts("-1");continue;
        }
        printf("%d\n", n * k);
        for(int i = 0; i < n;++i){
            int j = 0;
            for(auto va:dif){
                printf("%d ",va);
                ++j;
            }
            while(j < k){
                printf("%d ",*(dif.begin()));
                ++j;
            }
        }
        puts("");
    }
    return 0;
}
