#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    vector<ll> imp;
    imp.push_back(0);
    imp.push_back(1);
    while(imp.back() <= 1000000000ll)
        imp.push_back(imp[imp.size()-1]+imp[imp.size()-2]);
    imp.pop_back();
    while(t--){
        ll ar[2],n;
        scanf(" %lld %lld %lld",&ar[0],&ar[1],&n);
        if(ar[0] < ar[1]) swap(ar[0],ar[1]);
        int lo = 0, hi = imp.size()-1,ans;
        while(lo <= hi){
            ll mid = (lo+hi)>>1;
            if(imp[mid+1]*ar[0] + ar[1]*imp[mid] > n){
                ans = mid;
                hi = mid -1;
            }
            else
                lo = mid +1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
