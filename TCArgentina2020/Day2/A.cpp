#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 1000000

int main(){
    int n,q;
    scanf(" %d %d",&n,&q);
    int armax[n];
    int armin[n];
    for(int i = 0; i < n;++i){
        armax[i] = 50;
        armin[i] = 0;
    }
    while(q--){
        int type,l,r,v;
        scanf(" %d %d %d %d",&type,&l,&r,&v);
        --l,--r;
        if(type == 1)
            for(int i = l; i <= r;++i)
                armin[i] = max(armin[i],v);
        else
            for(int i = l; i <= r;++i)
                armax[i] = min(armax[i],v);
    }
    bool posi = 1;
    for(int i = 0; i < n && posi;++i)
        if(armax[i] < armin[i]) posi = 0;
    if(!posi){puts("-1");return 0;}
}
