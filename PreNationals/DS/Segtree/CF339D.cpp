#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
int n;
int t[2*N];
int colors[2*N];

void build(){
    for(int i = n-1; i > 0;--i){
        if(colors[i<<1] == 1) t[i] = t[i<<1] | t[i<<1|1], colors[i] = 0;
        else t[i] = t[i<<1] ^ t[i<<1|1], colors[i] = 1;
    }
}

void modify(int p, int val){
    for(t[p+=n] = val; p>>=1;){
        if(colors[p<<1] == 1) t[p] = t[p<<1] | t[p<<1|1];
        else t[p] = t[p<<1] ^ t[p<<1|1];
    }
}

int main(){
    int m;
    scanf(" %d %d",&n,&m);
    n = 1<<n;
    for(int i = 0; i < n;++i){
        scanf(" %d",&t[i+n]);
        colors[i+n] = 1;
    }
    build();
    while(m--){
        int p,v;
        scanf(" %d %d",&p,&v);
        modify(p-1,v);
        printf("%d\n",t[1]);
    }
    return 0;
}
