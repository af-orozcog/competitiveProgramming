#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;

vector<ll> phi;
vector<ll> sums;

void sett(){
    for(int i = 1; i < phi.size();++i) phi[i] = i-1;
    phi[1] = 2;
    for(int i = 2; i < phi.size();++i){
        if(phi[i] == i-1){
            for(int j = i*2; j < phi.size();j+=i) phi[j] -= phi[j]/i;
        }
    }

    for(int i = 1; i < phi.size();++i){
        sums[i] = phi[i];
        sums[i] += sums[i-1];
    }
}

int gcd(int a, int b){
    return b == 0? a : gcd(b,a%b);
}


int getAns(ll n, ll which){
    int ans;
    for(int i = 0; i <= n && which;++i){
        if(gcd(n,i) == 1) --which;
        if(which == 0) ans = i;
    }
    return ans;
}

int main(){
    phi.resize(10000000,0);
    sums.resize(10000000,0);
    sett();
    ll n;
    while(scanf(" %lld",&n) == 1 && n){
        int val = lower_bound(sums.begin(),sums.end(),n)-sums.begin();
        printf("%d/%d\n",getAns(val,n-sums[val-1]),val);
    }
    return 0;
}
