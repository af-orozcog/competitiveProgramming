#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        ll lo = 1, hi = 10000000,ans;
        while(lo <= hi){
            ll mid = (lo+hi)>>1;
            ll val = (mid*(mid-1ll))>>1;
            if(val <= n) ans = mid, lo = mid +1ll;
            else hi = mid -1ll;
        }
        n -= (ans*(ans-1ll))>>1;
        string show = "733";
        for(int i = 0; i < n;++i)
            show += '1';
        for(int i = 0; i < ans-2;++i)
            show += '3';
        show += '1';
        reverse(show.begin(),show.end());
        cout << show << "\n";
        //cout << ans << " " << n << "\n";
    }
    return 0;
}
