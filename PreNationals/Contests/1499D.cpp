#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll binExp(ll n, ll p){
    ll ans = 1;
    while(p){
        if(p&1) ans = ans*n;
        n = n*n;
        p >>= 1;
    }
    return ans;
}

vector<int> posi;

void init(){
    posi.resize(30000002,0);
    for(ll i = 2; i < 30000002;++i){
        if(posi[i] == 0){
            for(ll j = i; j < 30000002;j+=i)
                posi[j] += 1;
        }
    }
}


int main(){
    init();
    int t;
    scanf(" %d",&t);
    while(t--){
        int c,d,x;
        scanf(" %d %d %d",&c,&d,&x);
        int upTo = sqrt(x);
        ll ans = 0;
        for(int i = 1; i <= upTo;++i){
            if(x % i == 0){
                int see = x/i +d;
                if(see % c == 0)
                    ans += binExp(2,posi[see/c]);
                if(x/i != i){
                    int see = x/(x/i) + d;
                    if(see % c == 0)
                        ans += binExp(2,posi[see/c]);
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
