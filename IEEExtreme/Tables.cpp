#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll c,n,p,w;
    scanf(" %lld %lld %lld %lld",&c,&n,&p,&w);
    if(p <= c)
        printf("%lld\n",min(n,w/c));
    else{
        ll res = (w / p)*p;
        ll see = w-res;
        printf("%d\n",see>=c);
    }
    return 0;
}
