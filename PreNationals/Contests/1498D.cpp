#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll DIV = 100000;

ll ceil(ll x, ll y) {
    return (x+y-1)/y;
}

ll operation(int t, ll x, ll cur){
    if(t == 1)
        return cur + ceil(x,DIV);
    else
        return ceil(x*cur,DIV);
}

int main(){
    ll n,m;
    scanf(" %lld %lld",&n,&m);
    int t[n]; ll x[n]; int y[n];
    for(int i = 0; i < n;++i)
        scanf(" %d %lld %d",&t[i],&x[i],&y[i]);
    vector<int> ans(m+1,-1);
    vector<vector<int>> seen(2,vector<int>(m+1,0));
    seen[0][0] = 1;

    for(int i = 0; i < n;++i){
        seen[1] = seen[0];
        for(int j = 0; j <= m;++j){
            if(seen[0][j]){
                ll cur = j;
                cur = operation(t[i],x[i],cur);
                for(int k = 1; k <= y[i];++k){
                    if(cur > m) break;
                    if(seen[0][cur]) break;

                    seen[1][cur] = 1;
                    ans[cur] = i+1;
                    cur = operation(t[i],x[i],cur);
                }
            }
        }
        seen[0] = seen[1];
    }
    for(int i = 1; i <= m;++i)
        printf("%d ",ans[i]);
    puts("");
    return 0;
}
