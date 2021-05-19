#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int t[2 * N];

void build(){
    for(int i = n-1; i > 0;--i) t[i] = t[i<<1] + t[i<<1|1];
}


void modify(int p, int val){
    for(t[p += n] = val; p > 1; p>>=1) t[p>>1] = t[p] + t[p^1];
}

//this is a query for a range [l,r)
int query(int l, int r){
    int ans = 0;
    for(l += n, r +=n;l < r;l>>=1,r>>=1){
        if(l & 1) ans += t[l++];
        if(r & 1) ans += t[--r];
    }
    return ans;
}

int main(){
    scanf(" %d",&n);
    for(int i = 0; i < n;++i) scanf(" %d",&t[n+i]);
    build();
    printf("%d\n",query(0,10));
    return 0;
}
