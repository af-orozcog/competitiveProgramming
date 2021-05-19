#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int t[2*N];

void modify(int l, int r, int val){
    for(l += n,r += n; l < r;l>>=1,r>>=1){
        if(l&1) t[l++] += val;
        if(r&1) t[--r] += val;
    }
}

int query(int p){
    int ans = 0;
    for(p+= n; p > 0;p>>=1) ans += t[p];
    return ans;
}

void push(){
    for(int i = 1; i < n;++i){
        t[i<<1] += t[i];
        t[i<<1|1] += t[i];
        t[i] = 0;
    }
}

int main(){
    int n;
    scanf(" %d",&n);
    for(int i = 0; i < n;++i) scanf(" %d",&t[i+n]);
    modify(0,10,1);
    push();
    for(int i = 0; i < n;++i) printf("%d ",t[i+n]);
    puts("");
    return 0;
}
