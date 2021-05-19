#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

bitset<1000000> posi;
ll upTo = 1000000;

void sett(){
    posi.set();
    posi[0] = posi[1] = 0;
    for(ll i = 2; i < upTo;++i){
        if(posi[i]){
            for(ll j = i*i; j < upTo;j+=i) posi[j] = 0;
        }
    }
}

ll binPow(ll n, ll y, ll mod){
    ll ans = 1;
    while(y){
        if(y&1) ans = (ans*n)%mod;
        y >>= 1;
        n *= n;
        if(n >= mod) n %= mod;
    }
    return ans;
}


int main(){
    sett();
    int see;
    while(scanf(" %d",&see) == 1 && see){
        if(posi[see]){
            printf("%d is normal.\n",see);
            continue;
        }
        bool is = 1;
        for(int i = 2; i < see && is;++i){
            if(binPow(i,see,see) != i) is = 0;
        }
        if(is) printf("The number %d is a Carmichael number.\n",see);
        else printf("%d is normal.\n",see);
    }
    return 0;
}
