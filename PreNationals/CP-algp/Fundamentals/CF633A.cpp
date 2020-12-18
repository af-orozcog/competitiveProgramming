#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(int a, int b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


void changeXY(ll a, ll b, ll &x, ll &y, ll cnt){
    x += cnt * b;
    y -= cnt * a;
}


bool any_solution(ll a, ll b, ll c){
    ll x,y;
    ll g = gcd(a,b,x,y);
    if(c % g)
        return 0;
    x *= c/g;
    y *= c/g;
    a /= g;
    b /= g;
    changeXY(a,b,x,y,(-x)/b);
    if(x < 0) changeXY(a,b,x,y,1);
    return x >= 0 && y >= 0;
}


int main(){
    ll a,b,c;
    scanf(" %lld %lld %lld",&a,&b,&c);
    if(any_solution(a,b,c))
        puts("Yes");
    else puts("No");
    return 0;
}
