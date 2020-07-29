#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
char see[(2*100000)+4];
ll BIT[(2*100000)+4];

ll query(int x){
    ll ans = 0;
    while(x){
        ans += BIT[x];
        x -= (x&(-x));
    }
    return ans;
}

void change(ll delta,int x){
    while(x <= n){
        BIT[x] += delta;
        x += (x&(-x));
    }
}

int where(ll x){
    int lo = 1, hi = n,ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        ll que = query(mid);
        if(que >= x)
            hi = mid -1,ans = mid;
        else
            lo = mid + 1;
    }
    return ans;
}

int main(){
    scanf("%d %d",&n,&m);
    scanf(" %s",see);
    for(int i = 1; i <= n;++i)
        change(1,i);
    vector<set<int>> let(255);
    for(int i = 0; i < n;++i)
        let[see[i]].insert(i+1);
    while(m--){
        int l,r; char c;
        scanf(" %d %d %c",&l,&r,&c);
        int posL = where(l);
        int posR = where(r);
        vector<int> er;
        auto from = let[c].lower_bound(posL);
        for(; from != let[c].end() && (*from) <= posR;++from)
            er.push_back(*from);
        for(auto va:er){
            change(-1,va);
            let[c].erase(va);
        }
    }
    set<pair<int,char>> ans;
    for(int i = 0; i < 255;++i){
        for(auto va:let[i])
            ans.insert({va,i});
    }
    for(auto va:ans)
        printf("%c",va.second);
    puts("");
    return 0;
}
