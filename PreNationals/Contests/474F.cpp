#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+2;
int t[2][2*MAX];
int n;
const int top = 1e9;

int gcd(int a, int b){
    return b == 0? a: gcd(b,a%b);
}

void build(){
    for(int i = n-1; i > 0;--i){
        t[0][i] = min(t[0][i<<1],t[0][i<<1|1]);
        t[1][i] = gcd(t[1][i<<1],t[1][i<<1|1]);
    }
}


int query1(int l, int r){
    int ans = INT_MAX;
    for(l += n, r += n; l < r;l>>=1,r>>=1){
        if(l&1) ans = min(ans,t[0][l++]);
        if(r&1) ans = min(ans,t[0][--r]);
    }
    return ans;
}

int query2(int l, int r){
    int ans = -1;
    for(l += n, r += n; l < r; l>>=1, r>>=1){
        if(l&1){
            if(ans == -1) ans = t[1][l++];
            else ans = gcd(ans,t[1][l++]);
        }
        if(r&1){
            if(ans == -1) ans = t[1][--r];
            else ans = gcd(ans,t[1][--r]);
        }
    }
    return ans;
}

int main(){
    scanf(" %d",&n);
    map<int,vector<int>> mp;

    for(int i = 0; i < n;++i){
        scanf(" %d",&t[0][i+n]);
        t[1][i+n] = t[0][i+n];
        mp[t[0][i+n]].push_back(i);
    }
    build();
    int q;
    scanf(" %d",&q);
    while(q--){
        int l,r;
        scanf(" %d %d",&l,&r);
        --l;
        int imp1 = query1(l,r);
        int imp2 = query2(l,r);
        if(imp1 == imp2){
            int les = lower_bound(mp[imp1].begin(),mp[imp1].end(),r)-lower_bound(mp[imp1].begin(),mp[imp1].end(),l);
            printf("%d\n",r-l-les);
        }
        else printf("%d\n",r-l);
    }
    return 0;
}
