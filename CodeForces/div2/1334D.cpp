#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n,l,r;
        scanf(" %lld %lld %lld",&n,&l,&r);
        ll leftL = n*(n-1ll)-l;
        ll hi = n,lo = 0, ans;
        while(lo <= hi){
            ll mid = (hi+lo)>>1;
            if(mid*(mid-1ll)-1 >= leftL)
                ans = mid,hi = mid-1ll;
            else
                lo = mid +1ll;
        }
        ll from = (ans*(ans-1ll)-1)-leftL;
        ans = (n-(ans)+1)%n;
        ll ot = ((from>>1)+1)+ans;
        ll siz = r-l+1;
        for(ll i = from,j = ot,k = 0; k < siz;++i,++k){
             if(ans == n)
                printf("1");
             else if(i&1){
                printf("%lld ",j++);
                if(j > n)
                    ++ans,j= ans+1;
                if(ans > n)
                    ans = 1;
            }
            else
                printf("%lld ",ans);
        }
        puts("");
    }
    return 0;
}
