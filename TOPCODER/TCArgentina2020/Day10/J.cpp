#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> primes;
bitset<1000006> po;

void sieve(){
    po.set();
    po[0] = po[1] = 0;
    for(ll i = 2; i < 1000006ll;++i){
        if(po[i]){
            for(ll j = i*i; j < 1000006ll;j+=i) po[j] = 0;
            primes.push_back((int)i);
        }
    }
}

int main(){
    sieve();
    int a,b,k;
    scanf(" %d %d %d",&a,&b,&k);
    vector<int> prefix(1000006,0);
    for(int i = 1; i < 1000006;++i){
        prefix[i] += prefix[i-1];
        if(po[i])
            ++prefix[i];
    }
    int lo = 1, hi = b-a+1, ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        bool good = 1;
        for(int i = a; i <= b-mid+1 && good;++i)
            if(prefix[i+mid-1]-prefix[i-1] < k) good = 0;
        if(good)
            hi = mid -1, ans = mid;
        else
            lo = mid + 1;
    }
    printf("%d\n",ans);
    return 0;
}
