#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<int> primes;
bitset<100000001> posi;

void init(){
    posi.set();
    posi[0] = posi[1] = 0;
    for(ll i = 2; i < 100000001;++i){
        if(posi[i]){
            primes.push_back((int)i);
            for(ll j = i*i; j < 100000001;j += i) posi[j] = 0;
        }
    }
}

ll fastSum(ll n){
    return (n*(n+1))>>1;
}

pair<int,int> answer(ll val){
    ll lo = 1, hi = 100000,ans;
    while(lo <= hi){
        ll mid = (lo+hi)>>1;
        ll check = fastSum(mid);
        if(check >= val)
            ans = mid,hi = mid -1;
        else
            lo = mid + 1;
    }
    return make_pair(ans,ans-(fastSum(ans)-val));
}

int main(){
    primes.push_back(-1);
    init();
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int index = lower_bound(primes.begin(),primes.end(),n)-primes.begin();
        if(index == primes.size() || primes[index] != n)
            puts("-1");
        else{
            pair<int,int> ans = answer(index);
            printf("%d %d\n",ans.first,ans.second);
        }
    }
    return 0;
}
