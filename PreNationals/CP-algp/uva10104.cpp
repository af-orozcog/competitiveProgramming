#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1,y1;
    ll g = gcd(b, a % b,x1,y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}


int main(){
    ll a,b;
    while(scanf(" %lld %lld",&a,&b) == 2){
        ll x,y;
        ll g = gcd(a,b,x,y);
        printf("%lld %lld %lld\n",x,y,g);
    }
    return 0;
}
