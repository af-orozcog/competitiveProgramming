#include<bits/stdc++.h>
#define pb push_back
using namespace std;

bitset<10000> po;
vector<int> primes;

void sieve(){
    po.set();
    po[0] = po[1] = 0;
    for(int i = 2; i < 10000;++i){
        if(po[i]){
            for(int j = i*i; j < 10000;j+=i) po[j] = 0;
            primes.pb(i);
        }
    }
}

int main(){
    sieve();
    int n;
    scanf(" %d",&n);
    int ind  = lower_bound(primes.begin(),primes.end(),n)-primes.begin();
    printf("%d\n",primes[ind]);
    for(int i = 0; i < n-1;++i) printf("%d %d\n",i+1,i+2);
    printf("1 %d\n",n);
    int to = primes[ind] - n;
    for(int i = 0,j = 1, k = (n>>1)+1; i < to;++i,++j,++k) printf("%d %d\n",j,k);
    return 0;
}
