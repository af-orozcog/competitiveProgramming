#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX 10000005

vector<ll> primes;
vector<bool> posi;
ll calc(ll p, ll to){
    return to/p;
}


ll calcR(ll p, ll from, ll to){
    return calc(p,to)-calc(p,from-1);
}

ll magic(ll p, ll from, ll to){
    ll ans = 0;
    ll v = p;
    ll d = -1;
    while(d){
        d = calcR(v,from,to);
        v *= p;
        ans += d;
    }
    return ans;
}

void sett(){
    posi.resize(MAX,1);
    for(int i = 4; i < MAX;i+=2) posi[i] = 0;
    primes.push_back(2);
    for(ll i = 3; i < MAX;i+=2){
        if(posi[i]){
            for(ll j = i*i; j < MAX; j+= i) posi[j] = 0;
            primes.push_back(i);
        }
    }

}


int main(){
    sett();
    int t;
    scanf(" %d",&t);
    while(t--){
        int l1,r1,l2,r2;
        scanf(" %d %d %d %d",&l1,&r1,&l2,&r2);
        bool ans = 1;
        for(auto p: primes){
            if(p > r1 && p > r2) break;
            ll see1 = magic(p,l1,r1);
            ll see2 = magic(p,l2,r2);
            if(see1 > see2) ans = 0;
            if(!ans)break;
        }
        if(ans) puts("Yes");
        else puts("No");
    }
}
