#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll modPow(ll a, ll b, ll mod){
    ll ans = 1;
    a = a % mod;
    while(b){
        if(b&1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}


ll dig3(ll a, ll b){
    long double p = (double)b*log10(a);

    long double d = p - floor(p);

    d = pow(10,d);

    return d * 100ll;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll a,b;
        scanf(" %lld %lld",&a,&b);
        cout << dig3(a,b) << "..." << setw(3) << setfill('0') << modPow(a,b,1000) << "\n";
    }
    return 0;
}
