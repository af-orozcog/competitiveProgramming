#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> tuo;

ll binExp(ll n, ll mod){
    ll ans = 1;
    ll act = 2;
    while(n){
        if(n&1) ans = (ans*act);
        if(ans >= mod) ans %= mod;
        act = act*act;
        if(act >= mod) act %= mod;
        n >>= 1;
    }
    return ans;
}

void phi(int n){
    tuo.resize(n+1);
    for(int i = 0; i <= n;++i)
        tuo[i] = i;

    for(int i = 2; i <= n;++i){
        if(tuo[i] == i){
            for(int j = i; j <= n;j+= i)
                tuo[j] -= tuo[j]/i;
        }
    }
}


int main(){
    freopen("calc.in","r",stdin);
    freopen("calc.out","w",stdout);
    phi(1000000);
    int n,m;
    scanf(" %d %d",&n,&m);
    double use = log2(m);
    /*if(__gcd(n,m) == 1){
        ll val = binExp(n,tuo[m]);
        val = binExp(val,tuo[m]) + 1;
        if(val == m) val = 0;
        printf("%lld\n",val);
    }*/
    /*else*/ if((double)n >= use){
        ll imp = tuo[m] + binExp(n,tuo[m]);
        ll val = binExp(imp,m) +1;
        if(val == m) val = 0;
        printf("%lld\n",val);
    }
    else{
        ll imp = binExp(n,LLONG_MAX);
        ll val = binExp(imp,m) +1;
        if(val == m) val = 0;
        printf("%lld\n",val);
    }
    return 0;
}
