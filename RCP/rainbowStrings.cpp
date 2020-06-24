#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll pow(ll a, ll b, ll mod){
    ll rta = 1;
    while(b){
        if(b&1){
            rta*=a;
            rta%=mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return rta;
}


int main(){
    string re;
    cin >> re;
    ll mod = 11092019;
    vector<ll> nums(26,0);
    ll ans = pow(2,re.size(),mod);
    cout << ans <<"\n";
    for(int i = re.size()-1; i > -1;--i){
        ans -= pow(2,nums[re[i]-'a']+(re.back()==re[i]),mod);
        if(abs(ans) >= mod) ans %= mod;
        if(ans < 0) ans += mod;
        nums[re[i]-'a'] += (ll)re.size()-(ll)i-1ll;
    }
    cout << ans << "\n";
    return 0;
}
