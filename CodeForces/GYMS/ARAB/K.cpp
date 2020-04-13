#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000007;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k,l,r;
        scanf(" %d %d %d %d",&n,&k,&l,&r);
        ll dp[3][3][k+1];
        memset(dp,0,sizeof(dp));
        ll ar[3];
        int d = (r+1-l)/3;
        for(int i = 0; i < 3; ++i){
            ar[i]=d;
        }
        for(int i = l+d*3;i<=r; ++i ){
            ar[i%3]++;
        }
        for(int i = 0; i < 3;++i){
            for(int j = 0; j < 3;++j)
                dp[i][j][0] = (ar[i]*ar[j])%MOD;
        }
        for(int i= 2; i < n;++i){
            for(int j = 0; j < 3;++j){
                for(int l = 0; l < 3;++l){
                    for(int w = k; w > -1;--w){
                        if(w > 0){
                            dp[j][l][w] += ((dp[(3-((j+l)%3))%3][j][w-1])*ar[l])%MOD;
                            dp[j][l][w] %= MOD;
                        }
                        int mo = (j+l)%3;
                        for(int q = 0; q < 3;++q){
                            if((q+mo)%3 == 0)continue;
                            dp[j][l][w] += (dp[q][j][w]*ar[l])%MOD;
                            dp[j][l][w] %=  MOD;
                        }
                    }
                }
            }
        }
        ll ans = 0;
        for(int i = 0; i < 3;++i){
            for(int j = 0; j < 3;++j){
               ans += dp[i][j][k];
               ans = ans % MOD;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
