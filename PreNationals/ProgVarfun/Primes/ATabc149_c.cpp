#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> primes;
bitset<1000000> posi;
void init(){
    posi.set();
    posi[0] = posi[1] = 0;
    for(ll i = 1; i < 1000000;++i){
        if(posi[i]){
            primes.push_back((int)i);
            for(ll j = i*i; j < 1000000;j+=i) posi[j] = 0;
        }
    }
}


int main(){
    init();
    int n;
    scanf(" %d",&n);
    int index = lower_bound(primes.begin(),primes.end(),n) - primes.begin();
    printf("%d\n",primes[index]);
    return 0;
}
