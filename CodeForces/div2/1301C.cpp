#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    for(int i = 0; i < t;++i){
        ll n,k;
        scanf(" %lld %lld",&n,&k);
      //  if(i == 109) printf("%lld%lld\n",n,k);
        ll ones = k;
        ll ba = (n*(n+1ll))>>1;
        if(ones + k >= n){
            ones = n - k;
            printf("%lld\n",ba - ones); continue;
        }
        if(k == 1){
            ll us1 = 0,us2 = 0;
            if(n&1) us2 = us1 = n >>1;
            else us1 = n>>1, us2 = (n>>1)-1;
            ll le = ((us1*(us1+1ll))>>1) + ((us2*(us2+1ll))>>1);
            printf("%lld\n",ba - le);
            continue;
        }
        ll spa = (k +1);
        ll see = (n-k)/spa;
        ll les = 0;
        if((n-k) % spa){
            les = (((see+1ll)*(see+2ll))>>1)*((n-k) % spa) + (spa-((n-k) % spa))*((see*(see+1ll))>>1);
        }
        else
            les += ((see*(see+1ll))>>1)*(k+1ll);
        printf("%lld\n",ba-les);
    }
    return 0;
}
