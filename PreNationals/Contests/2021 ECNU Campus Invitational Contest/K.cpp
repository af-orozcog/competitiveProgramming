#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int l,k;
    scanf(" %d %d",&l,&k);
    ll S = 100000;
    ll upTo = sqrt(l+2*k-1);
    vector<bool> posi(upTo+1,1);
    posi[0] = posi[1] = 0;
    vector<ll> primes;
    for(ll i = 2; i <= upTo;++i){
        if(posi[i]){
            for(ll j = i*i; j <= upTo;j+=i) posi[j] = 0;
            primes.push_back(i);
        }
    }

    vector<bool> see(S);
    int K = ((l+2*k)-l)/S;
    if(((l+2*k)-l)%S) ++K;
    int ans = 0;
    for(int i = 0; i < K;++i){
        fill(see.begin(),see.end(),1);
        ll start = i*S+l;
        for(auto p:primes){
            ll imp = (start+p-1)/p;
            ll from = max(p,imp) *p - start;
            for(; from < S; from+=p)
                see[from] = 0;
        }

        if(start == 0)
            see[0] = see[1] = 0;
        for(int j = 0; j < S && j + start < (l+2*k);++j){
            if(see[j]) ++ans;
        }
    }
    if(ans > k) puts("Yes");
    else puts("No");
    return 0;
}
