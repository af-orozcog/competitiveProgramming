#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> primes;
bitset<100001> posi;

void init(){
    posi.set();
    posi[0] = posi[1] = 0;
    int upTo = sqrt(100001);
    for(ll i = 2; i <= upTo;++i){
        if(posi[i]){
            for(ll j = i*i; j < 100001;j+=i) posi[j] = 0;
        }
    }
    for(ll i = 2; i < 100001;++i)
        if(posi[i])
            primes.push_back(i*i);
}

int main(){
    init();
    int q;
    scanf(" %d",&q);
    while(q--){
        ll lo,hi;
        scanf(" %lld %lld",&hi,&lo);
        int index1 = upper_bound(primes.begin(),primes.end(),lo)-primes.begin();
        int index2 = upper_bound(primes.begin(),primes.end(),hi)-primes.begin();
        printf("%d %d\n",index2,max(index2-index1,0));
    }
    return 0;
}
