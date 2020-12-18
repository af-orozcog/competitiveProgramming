#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int upTo = sqrt(100000000);
    vector<bool> isPrime(upTo+1,1);
    vector<int> primes;
    isPrime[0] = isPrime[1] = 0;
    int co = 1;
    int S = 1000000;
    for(ll i = 2; i <= upTo;++i){
        if(isPrime[i]){
            for(ll j = i*i; j <= upTo; j+= i)
                isPrime[j] = 0;
            primes.push_back((int)i);
        }
    }
    isPrime.resize(S);
    for(int i = 0; S*i <= 100000000;++i){
        fill(isPrime.begin(),isPrime.end(),1);
        int start = S*i;
        for(auto p: primes){
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for(; j < S; j+= p)
                isPrime[j] = 0;
        }
        if(i == 0)
            isPrime[0] = isPrime[1] = 0;
        for(int j = 0; j < S && start + j <= 100000000;++j){
            if(isPrime[j]){
                if(co % 100 == 1)
                    printf("%d\n",start + j);
                ++co;
            }
        }
    }
    return 0;
}
