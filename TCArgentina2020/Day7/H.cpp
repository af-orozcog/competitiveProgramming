#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sqr(ll n){
    ll lo = 1, hi = 100000000;
    ll ans = 1;
    while(lo <= hi){
        ll mid = (lo+hi)>>1;
        if(mid*mid <= n)
            ans = mid, lo = mid +1ll;
        else
            hi = mid - 1ll;
    }
    return ans;
}

int main(){
    ll n;
    scanf(" %lld",&n);
    if(n == 1ll){puts("NO");return 0;}
    vector<int> primes;
    ll to = sqr(n);
    for(ll i = 2; i <= to && n != 1;++i){
        int add = 0;
        if(n % i == 0){
            while(n % i == 0){
                ++add;
                n /= i;
            }
        }
        if(add)
            primes.push_back(add);
    }
    if(n != 1)
        primes.push_back(1);
    int odd = 0;
    for(auto va:primes)
        odd += (va&1);
    if(odd > 1) puts("NO");
    else puts("YES");
    return 0;
}
