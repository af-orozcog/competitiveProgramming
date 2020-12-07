#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd_extended(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    ll x1,y1;
    ll g = gcd_extended(b,a%b,x1,y1);
    x = y1;
    y1 = x1 - (a/b)*y1;
    return g;
}


void changeXY(ll a, ll b, ll &x, ll &y, ll cnt){
    x += cnt * b;
    y -= cnt * a;
}


bool any_solution(ll a, ll b, ll c){
    ll x,y;
    ll g = gcd_extended(a,b,x,y);
    if(c % g)
        return 0;
    a /= g;
    b /= g;
    changeXY(a,b,x,y,(-x)/b);
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
