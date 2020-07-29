#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1000000007;

static ll power(ll x, ll y)
{
    ll res = 1;
    x = x % mod;

   if (x == 0ll) return 0ll; // In case x is divisible by p;

    while (y > 0ll)
    {
        if((y & 1)==1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

int main(){
    string re;
    cin >> re;
    vector<ll> sum(re.size(),0);
    for(int i = 0; i < re.size();++i)
        sum[i] = (re[i] == 'a');
    for(int i = 1; i < re.size();++i)
        sum[i] += sum[i-1];
    ll ans = 0;
    for(int i = 0; i < re.size();++i){
        ll add = 0;
        if(re[i] == 'b'){
            add = power(2,sum[i]);
            --add;
            if(add < 0) add += mod;
        }
        ans += add;
        if(ans >= mod) ans -= mod;
    }
    printf("%lld\n",ans);
    return 0;
}
