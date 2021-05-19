#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1,y = 0;
        return a;
    }
    ll x1,y1;
    ll g = gcd(b, a% b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

int main(){
    ll a,b,c;
    scanf(" %lld %lld %lld",&a,&b,&c);
    ll x,y;
    ll g = gcd(a,b,x,y);
    if(c % g != 0) {puts("No"); return 0;}
    x *= c/g;
    y *= c/g;

    ll K = (-x*g)/b;
    if((-x*g) > 0 && (-x*g) % b != 0) ++K;

    x += K*(b/g);
    y -= K*(a/g);

    if(y >= 0) puts("Yes");
    else puts("No");

    return 0;
}
