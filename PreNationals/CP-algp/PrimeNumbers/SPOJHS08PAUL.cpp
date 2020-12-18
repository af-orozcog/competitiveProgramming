#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<int> primes;
bitset<10000001> posi;
vector<int> sums(10000001);

int main(){
    int t;
    scanf(" %d",&t);
    posi.set();
    posi[0] = posi[1] = 0;
    for(int i = 2; i < 3700;++i){
        if(posi[i]){
            for(int j = i*i; j < 10000001; j+= i) posi[j] = 0;
        }
    }

    for(ll i = 1; true;++i){
        ll val = i*i;
        if(val >= 10000001)
            break;
        for(ll j = 0;true;++j){
            ll def = val + j*j*j*j;
            if(def >= 10000001) break;
            if(posi[def])
                sums[def] = 1;
        }
    }
    for(int i = 1; i < 10000001;++i)
        sums[i] += sums[i-1];
    while(t--){
        int n;
        scanf(" %d",&n);
        printf("%d\n",sums[n]);
    }
    return 0;
}
