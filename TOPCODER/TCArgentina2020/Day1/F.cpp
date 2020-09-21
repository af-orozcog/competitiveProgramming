#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll modPow(ll n,ll m, ll mod){
    ll ans = 1;
    ll temp = n%mod;
    while(m){
        if(m&1) ans = (ans*temp) % mod;
        m >>= 1;
        temp *= temp;
        temp %= mod;
    }
    return ans;
}

ll dp[33][102];
int nums[50001];
ll mod = 1000000007;

ll ans[2][102];

int main(){
    int n,b,k,x;
    scanf(" %d %d %d %d",&n,&b,&k,&x);
    for(int i = 0; i < n;++i){
        scanf(" %d",&nums[i]);
        ++dp[0][nums[i]%x];
    }
    for(ll i = 1; i < 30;++i){
        ll send = 1;
        ll mul = modPow(10,send<<i,x);
        for(int j = 0; j < 101;++j){
            for(int q = 0; q < 101;++q){
                ll see = dp[i-1][j]*dp[i-1][q];
                see %= mod;
                ll where = (j*mul + q)%x;
                dp[i][where]+= see;
                if(dp[i][where] >= mod)
                    dp[i][where] -= mod;
            }
        }
    }
    int already = 0;
    ans[0][0] = 1;
    int tama = 1;
    int p = 0;
    while(b){
        if(b&1){
             ll mul = modPow(10,already,x);
             for(int j = 0; j < 101;++j){
                for(int q = 0; q < 101;++q){
                    ll see = ans[0][j]*dp[p][q];
                    see %= mod;
                    ll where = (q*mul + j)%x;
                    ans[1][where]+= see;
                    if(ans[1][where] >= mod)
                        ans[1][where] -= mod;
                }
            }
            already += tama;
            memcpy(ans[0],ans[1],sizeof(ans[1]));
            memset(ans[1],0,sizeof(ans[1]));
        }
        tama <<=1;
        ++p;
        b >>= 1;
    }
    printf("%lld\n",ans[0][k]);
    return 0;
}
