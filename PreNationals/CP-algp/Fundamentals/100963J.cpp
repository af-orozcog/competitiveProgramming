#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b,ll &x, ll &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    ll x1,y1;
    ll g = gcd(b, a % b, x1,y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;
}

int main(){
    while(1){
        ll n,m,a,k;
        scanf(" %lld %lld %lld %lld",&n,&m,&a,&k);
        if(n == m && a == k && a == 0 && n == 0) break;
        ll see = n - k - a;
        m *= -1;
        if(see < 0) a *= -1, m *= -1,see *= -1;
        ll x,y,g;
        g = gcd(abs(a),abs(m),x,y);
        if(see % g != 0){
            puts("Impossible"); continue;
        }
        x *= see/g;
        y *= see/g;
        if(a < 0) x *= -1;
        if(m < 0) y *= -1;

        ll K = (-x*g)/m;
        if(m < 0 && (-x*g) % abs(m) != 0 && (-x*g*m) < 0) --K;
        if(m > 0 && (-x*g) % abs(m) != 0 && (-x*g*m) > 0) ++K;

        x += K*(m/g);
        y -= K*(a/g);
        K = (-y*g)/(-a);
        if((-a) < 0 && (-y*g) % abs(a) != 0 && (-y*g*-a) < 0) --K;
        if((-a) > 0 && (-y*g) % abs(a) != 0 && (-y*g*-a) > 0) ++K;
        x += K*(m/g);
        y -= K*(a/g);
        printf("%lld\n",x*abs(a) + a + k);
    }
    return 0;
}
