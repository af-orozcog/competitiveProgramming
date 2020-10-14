#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Pow(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = ans * a;
        b >>= 1;
        a*= a;
    }
    return ans;
}

int main(){
    ll n;
    scanf(" %lld",&n);
    ll ans = 2*3*pow(4,n-2) + (n-3)*3*3*pow(4,n-3);
    printf("%lld\n",ans);
    return 0;
}
