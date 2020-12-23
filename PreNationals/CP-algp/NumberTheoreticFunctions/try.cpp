#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> phi(int n){
    vector<ll> phi(n+1);

    for(int i = 0; i <= n;++i)
        phi[i] = i;

    for(int i = 2; i <= n;++i){
        if(phi[i] == i){
            for(int j = i; j <= n;j+=i)
                phi[j] -= phi[j]/i;
        }
    }
    return phi;
}

int coprimeN(int num,int n){
    int val;
    for(int i = 1; i <= num && n;++i)
        if(__gcd(num,i) == 1){
            val = i;
            --n;
        }
    return val;
}

int main(){
    vector<ll> use = phi(210000);
    for(int i = 1; i < use.size();++i)
        use[i] += use[i-1];
    ll n;
    while(scanf(" %lld",&n) && n){
        if(n == 1){
            puts("0/1");
            continue;
        }
        --n;
        int index = lower_bound(use.begin(),use.end(),n)-use.begin();
        n -= use[index-1];
        printf("%d/%d\n",coprimeN(index,n),index);
    }
    return 0;
}
