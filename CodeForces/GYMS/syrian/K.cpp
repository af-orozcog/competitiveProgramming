#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastSum(ll n){
    return (n*(n+1ll))>>1;
}

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        ll n,m,k,s;
        scanf(" %lld %lld %lld %lld",&n,&m,&k,&s);
        ll row = 0ll,col = 0ll;
        if((m-k)>= s){
            row = fastSum(m-k-s+1ll);
            row <<= 1;
            if(row >= 1000000007ll) row %= 1000000007ll;
        }
        if((n-k) >= s){
            col = fastSum(n-k-s+1ll);
            col <<= 1;
            if(col >= 1000000007ll) col %= 1000000007ll;
        }
        ll ans = 0;
        ans += n*row;
        if(ans >= 1000000007ll) ans %= 1000000007ll;
        ans += m*col;
        if(ans >= 1000000007ll) ans %= 1000000007ll;
        ll one = ((max(m-k,0ll))*(max(n-s+1ll,0ll))%1000000007ll)*max(m-k+1ll,0ll);
        if(one >= 1000000007ll) one %= 1000000007ll;
        one *= n;
        if(one >= 1000000007ll) one %= 1000000007ll;
        ll two = 0;
        if((n-1ll) >= s){
            two = fastSum(n-s);
            two <<= 1;
            two *= k;
            if(two >= 1000000007ll) two %= 1000000007ll;
            two *= max(m-k+1ll,0ll);
            if(two >= 1000000007ll) two %= 1000000007ll;
        }
        ans += one + two;
        if(ans >= 1000000007ll) ans %= 1000000007ll;
        one = (((max(n-k,0ll))*(max(m-s+1ll,0ll)))%1000000007ll)*(max(n-k+1ll,0ll));
        if(one >= 1000000007ll) one %= 1000000007ll;
        one *= m;
        two = 0;
        if((m-1ll) >= s){
            two = fastSum(m-s);
            two <<= 1;
            two *= k;
            if(two >= 1000000007ll) two %= 1000000007ll;
            two *= max(n-k+1ll,0ll);
            if(two >= 1000000007ll) two %= 1000000007ll;
        }
        ans += one + two;
        ll imp = fastSum(m-1);
        imp <<= 1;
        if(imp >= 1000000007ll) imp %= 1000000007ll;
        imp *= max(n-s+1ll,0ll);
        if(imp >= 1000000007ll) imp %= 1000000007ll;
        imp *= (max(n-k+1ll,0ll));
        if(imp >= 1000000007ll) imp %= 1000000007ll;
        ans += imp;
        if(ans >= 1000000007ll) ans %= 1000000007ll;
        imp = fastSum(n-1);
        imp <<= 1;
        if(imp >= 1000000007ll) imp %= 1000000007ll;
        imp *= max(m-s+1ll,0ll);
        if(imp >= 1000000007ll) imp %= 1000000007ll;
        imp *= max(m-k+1ll,0ll);
        ans += imp;
        if(ans >= 1000000007ll) ans %= 1000000007ll;
        ans <<= 2;
        if(ans >= 1000000007ll) ans %= 1000000007ll;
        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}
