#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll modPow(ll a, ll b){
    ll ans = 1;
    a %= 10;
    while(b){
        if(b&1) ans = ans * a % 10;
        a = a * a % 10;
        b >>= 1;
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll a,b;
        scanf(" %lld %lld",&a,&b);
        printf("%lld\n",modPow(a,b));
    }
    return 0;
}
