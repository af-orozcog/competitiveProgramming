#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

vector<int> primes;
bitset<1000000> posi;

void lel(){
    posi.set();
    posi[0] = posi[1] = 0;
    primes.push_back(1);
    for(ll i = 2; i < (ll)1000000;++i){
        if(posi[i]){
            for(ll j = i*i; j < (ll)1000000; j+=i) posi[j] = 0;
            primes.push_back((int)i);
        }
    }
}


int main(){
    lel();
    int t;
    scanf(" %d",&t);
    while(t--){
        int d;
        scanf(" %d",&d);
        int ans = 1;
        ll next1 = primes[lower_bound(primes.begin(),primes.end(),1+d)-primes.begin()];
        ll next2 = primes[lower_bound(primes.begin(),primes.end(),next1+d)-primes.begin()];
        printf("%lld\n",next1*next2);
    }
    return 0;
}
