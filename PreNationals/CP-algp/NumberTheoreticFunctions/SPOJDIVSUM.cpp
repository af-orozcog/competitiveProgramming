#include<bits/stdc++.h>
#define ll long long
using namespace  std;

vector<ll> factors(1000001,1);

void init(){
    for(ll i = 2; i < 1000001;++i){
        if(factors[i] == 1){
            factors[i] = i;
            for(ll j = i*i; j < 1000001;j+=i) factors[j] = i;
        }
    }
}

ll sumDivisors(int n){
    map<ll,ll> use;
    ll temp = n;
    while(n != 1){
        if(use.count(factors[n]))
            use[factors[n]]*=factors[n];
        else use[factors[n]] = factors[n]*factors[n];
        n /= factors[n];
    }
    ll ans = 1;
    for(auto va:use)
        ans *= (va.second-1)/(va.first-1);

    ans -= (ll)temp;
    return ans;
}


int main(){
    init();
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        printf("%lld\n",sumDivisors(n));
    }
    return 0;
}
