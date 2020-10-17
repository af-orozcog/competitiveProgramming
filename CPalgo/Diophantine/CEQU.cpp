#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcdExtended(ll a, ll b, ll &x, ll &y){
    if(!b){
        x = 1,y = 0;
        return a;
    }
    ll x1,y1;
    ll g = gcdExtended(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g){
    g = gcdExtended(a,b,x0,y0);
    if(c % g) return 0;

    x0 *= c/g;
    y0 *= c/g;
    if(a < 0) x0 = -x0;
    if(b < 0) y0 = -y0;
    return true;
}

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        ll a,b,c;
        scanf(" %lld %lld %lld",&a,&b,&c);
        ll x0,y0,g;
        if(find_any_solution(a,b,c,x0,y0,g))
            printf("Case %d: Yes\n",cas++);
        else
            printf("Case %d: No\n",cas++);
    }
    return 0;
}
