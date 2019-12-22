#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t;scanf(" %d",&t);
    while(t--){
        ll l,r;
        scanf(" %lld %lld",&l,&r);
        ll pre = (r*(r+1))>>1;
        pre -= (l*(l-1))>>1;
        ll big = 1;
        while(big < l || (big > l && big < r))
            big <<= 1;
        if(big > r) big>>= 1;
        ll le = 0;
        int cum = 0;
        while(big){
            if(big >= l && big <= r) --le;
            ll imp = (r/big -(l-1)/big)-cum;
            le -= imp*big;
            cum += imp;
            big >>= 1;
        }
        printf("%lld\n",pre+le);
    }
    return 0;
}
