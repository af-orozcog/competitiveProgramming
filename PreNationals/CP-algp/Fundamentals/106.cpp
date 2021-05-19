#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

ll gcd(ll a, ll b, ll &x, ll &y) {
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

void move(ll &x, ll &y,ll a, ll b, ll K){
    x += b*K;
    y -= a*K;
}


int main(){
    ll a,b,c;
    ll x1,x2;
    ll y1,y2;
    scanf(" %lld %lld %lld",&a,&b,&c);
    scanf(" %lld %lld",&x1,&x2);
    scanf(" %lld %lld",&y1,&y2);

    if(a == 0 && b == 0){
        if(c == 0) printf("%lld\n",(x2-x1+1LL)*(y2-y1+1LL));
        else puts("0");
        return 0;
    }
    if(a == 0){
        if(abs(c) % b == 0 && -c/b >= y1 && -c/b <= y2) puts("1");
        else puts("0");
        return 0;
    }
    if(b == 0){
        if(abs(c) % a == 0 && -c/a >= x1 && -c/a <= x2) puts("1");
        else puts("0");
        return 0;
    }

    ll x,y;
    ll g = gcd(abs(a),abs(b),x,y);
    if(abs(c) % g != 0){
        puts("0");return 0;
    }
    x *= (-c)/g;
    y *= (-c)/g;

    if(a < 0) x *= -1;
    if(b < 0) y*= -1;

    a /= g;
    b /= g;

    pair<ll,ll> f;
    pair<ll,ll> s;

    ll K = (x1 - x)/b;

    if(b < 0 && (x1-x) % abs(b) && x1-x >= 0) --K;
    if(b > 0 && (x1-x) % abs(b) && x1-x >= 0) ++K;

    move(x,y,a,b,K);
    f.first = x;

    if(x > x2){puts("0");return 0;}

    K = (x2-x)/b;

    move(x,y,a,b,K);
    f.second = x;

    K = (y1-y)/(-a);
    if((-a) < 0 && (y1-y) % abs(a) && y1-y >= 0) --K;
    if((-a) > 0 && (y1-y) % abs(a) && y1-y >= 0) ++K;

    move(x,y,a,b,K);
    s.first = x;

    if(y > y2){puts("0"); return 0;}

    K = (y2-y)/(-a);

    move(x,y,a,b,K);
    s.second = x;
    if(s.first > s.second) swap(s.first,s.second);

    pair<ll,ll> p = {max(f.first,s.first),min(f.second,s.second)};

    if(p.first > p.second) puts("0");
    else printf("%lld\n",(p.second-p.first)/ abs(b) +1LL);

    return 0;
}
