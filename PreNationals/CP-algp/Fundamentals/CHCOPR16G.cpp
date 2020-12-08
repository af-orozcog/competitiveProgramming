#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll gcd(ll a, ll b){
    return b == 0? a : gcd(b,a%b);
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll a,b;
        scanf(" %lld %lld",&a,&b);
        if(gcd(a,b) != 1)
            puts("-1");
        else
            printf("%lld\n",a*b - a - b + 1ll);
    }
    return 0;
}
