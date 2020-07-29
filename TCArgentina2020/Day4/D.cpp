#include<bits/stdc++.h>
#define ll long long
using namespace std;

int bad[(3*100000)+5];

int main(){
    int n,p;
    scanf(" %d %d",&n,&p);
    for(int i = 0; i < n;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        ++bad[a];
        ++bad[b];
    }
    ll select = 0;
    for(int i = 1; i <= n;++i){
        if(bad[i] >= p)
            ++select;
    }
    ll ans = (select*(select-1ll))>>1;
    printf("%lld\n",ans);
    return 0;
}
