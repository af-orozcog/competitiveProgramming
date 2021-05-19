#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> phi;
vector<ll> ans;

void sett(){
    phi.resize(2000000);
    ans.resize(2000000);
    for(int i = 2; i < phi.size();++i) phi[i] = i-1;
    phi[1] = 1;
    for(int i = 2; i < phi.size();++i){
        if(phi[i] == i-1){
            for(int j = i*2; j < phi.size();j+=i) phi[j] -= phi[j]/i;
        }
    }

    for(ll i = 1; i < ans.size();++i){
        for(ll j = i; j < ans.size();j+=i) ans[j] += phi[i]*i;
    }
}



int main(){
    sett();
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        printf("%lld\n",((ans[n]+1)*n)>>1);
    }
    return 0;
}
