#include<bits/stdc++.h>
#define ll long long
using namespace std;

bitset<1000001> posi;
vector<int> primes;

void init(){
    posi.set();
    posi[0] = posi[1] = 0;
    for(ll i = 2; i < 1000001;++i){
        if(posi[i]){
            for(ll j = i*i; j < 1000001;j+=i) posi[j] = 0;
            primes.push_back((int)i);
        }
    }
}

vector<bool> segmentedSieve(ll L, ll R) {
    // generate all primes up to sqrt(R)
    ll lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<ll> primes;
    for (ll i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int main(){
    init();
    int t;
    scanf(" %d",&t);
    int first = 0;
    while(t--){
        if(first)
            puts("");
        ll L,R;
        first = 1;
        scanf(" %lld %lld",&L,&R);
        vector<bool> see = segmentedSieve(L,R);
        for(int i = 0; i < see.size();++i)
            if(see[i])
                printf("%lld\n",L+i);
    }
    return 0;
}
