#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

ll fastSum(ll n){
    return ((n+1ll)*n)>>1ll;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n,k;
        scanf(" %lld %lld",&n,&k);
        if(k == 1){
            vector<char> show(n,'a');
            show[n-1] = show[n-2] = 'b';
            for(int i = 0; i < n;++i) printf("%c",show[i]);
            puts("");
            continue;
        }
        ll lo = 0, hi = 100000000, ans;
        while(lo <= hi){
            ll mid = (hi+lo)>>1;
            ll va = fastSum(mid);
            if(va < k){
                lo = mid + 1ll;
                ans = mid;
            }
            else
                hi = mid -1ll;
        }
        vector<char> show(n,'a');
        //cout << ans << endl;
        show[n-ans-1ll-1ll] = 'b';
        ll see = k - fastSum(ans);
        //cout << see << "\n";
        show[n-see] = 'b';
        for(int i = 0; i < n;++i) printf("%c",show[i]);
        puts("");
    }
}
