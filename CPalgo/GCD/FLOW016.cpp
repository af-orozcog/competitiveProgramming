#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll lcm(ll a, ll b){
    ll g = __gcd(a,b);
    return (a/g)*b;
}


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll a,b;
        scanf(" %lld %lld",&a,&b);
        ll g = __gcd(a,b);
        printf("%lld %lld\n",g,lcm(a,b));
    }
    return 0;
}
