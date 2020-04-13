#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

const ll M = 998244353;

ll fastSum(ll n){
    return (n*(n+1ll))>>1;
}

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    vector<ll> marked;
    ll sum = fastSum(n)-fastSum(n-k);
    for(ll i = 0; i < n;++i){
        int va;scanf(" %d",&va);
        if(va > n - k) marked.push_back(i);
    }
    ll ans = 1;
    for(int i = 0; i < marked.size()-1;++i){
        ll dist = marked[i+1]-marked[i];
        ans *= dist;
        ans = ans % M;
    }
    printf("%lld %lld\n",sum,ans);
}
