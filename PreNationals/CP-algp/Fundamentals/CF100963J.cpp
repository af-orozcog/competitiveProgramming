#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd_extended(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1,y = 0;
        return a;
    }
    ll x1,y1;
    ll g = gcd_extended(b, a % b, x1, y1);
    x = y1;
    y = x1- (a/b)*y1;
    return g;
}

ll gcd(ll a, ll b){
    return b == 0 ? a: gcd(b,a%b);
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b))*b;
}

int main(){
    ll n,m,a,k,imp;
    while(scanf(" %lld %lld %lld %lld",&n,&m,&a,&k) == 4){
        if(n == m && n == a && n == k && n == 0)
            break;
        ll mi = min(a,n);
        if(a == mi && n == mi)
            printf("%lld\n",mi + lcm(m,k));
        if(a > mi){
            ll x,y;
            imp = (a-n)%m;
            imp = m - imp;
            ll g = gcd_extended(k,m,x,y);
            if(imp % g){puts("Impossible");continue;}
            while(x < 0) x += m/g;
            x *= (imp/g);
            if(x)
                printf("%lld\n",a+k*x);
            else
                printf("%lld\n",a+lcm(m,k));
        }
        else{
            ll x,y;
            imp = (n-a)%k;
            imp = k - imp;
            ll g = gcd_extended(m,k,x,y);
            if(imp % g){puts("Impossible");continue;}
            while(x < 0) x += k/g;
            x *= (imp/g);
            printf("%lld\n",n+m*x);
        }
    }
    return 0;
}
