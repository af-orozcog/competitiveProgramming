#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int power(int val){
    int ans = 0;
    while(val != 1){
        ++ans;
        val = val >> 1;
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    int vals[32];
    vals[0] = 1;
    for(int i = 1; i < 32;++i) vals[i] = vals[i-1]<<1;
    while(t--){
        int n, w;
        scanf(" %d %d",&n,&w);
        int seen[32];
        memset(seen,0,sizeof(seen));
        for(int i = 0; i < n;++i){
            int see;
            scanf(" %d",&see);
            ++seen[power(see)];
        }
        int ans = 0;
        while(n){
            int left = w;
            for(int i = 31; i > -1;){
                if(seen[i] && vals[i] <= left){
                    --seen[i];
                    --n;
                    left -= vals[i];
                }
                else --i;
            }
            ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
