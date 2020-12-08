#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<ll> vals;
vector<ll> sums;
ll top = 10000000000000000LL;

ll answer(ll up){
    ll lo = 0, hi = vals.size()-1, ans = 0;
    while(lo <= hi){
        ll mid = (lo+hi)>>1;
        if(vals[mid] <= up)
            ans = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }
    return sums[ans];
}

int main(){
    top *= 4LL;
    vals.push_back(0);
    vals.push_back(2);
    sums.push_back(0);
    sums.push_back(2);
    while(vals.back() <= top){
        vals.push_back(vals.back()*4LL + vals[vals.size()-2]);
        sums.push_back(vals.back() + sums.back());
    }

    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        printf("%lld\n",answer(n));
    }

    return 0;
}
