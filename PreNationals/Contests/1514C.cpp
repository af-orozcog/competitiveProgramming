#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;


int MAX = 100005;
ll MOD = 1000000007;

ll gcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1,y = 0;
        return a;
    }
    ll x1,y1;
    ll g = gcd(b, a% b, x1,y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

ll modInverse(ll a, ll m){
    ll x, y;
    ll g = gcd(a,m,x,y);
    if(g != 1) return -1;
    return (x % m + m) % m;
}

int main(){
    int n;
    scanf(" %d",&n);
    vector<int> ans;
    for(int i = 1; i < n;++i){
        ll inv = modInverse(i,n);
        if(inv != -1)
            ans.push_back(i);
    }

    ll va = 1;
    for(int i = 0; i < ans.size();++i){
        va *= ans[i];
        if(va >= n) va %= n;
    }

    if(va != 1){
        ll inv = modInverse(va,n);
        int where = find(ans.begin(),ans.end(),inv)-ans.begin();
        ans.erase(ans.begin()+where);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for(auto va: ans) printf("%d ",va);
    puts("");
    return 0;
}
