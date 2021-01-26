#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int a,b,k;
        scanf(" %d %d %d",&a,&b,&k);
        map<int,ll> g1,g2;
        int nums1[k],nums2[k];
        for(int i = 0; i < k;++i)
            scanf(" %d",&nums1[i]);
        for(int i = 0; i < k;++i)
            scanf(" %d",&nums2[i]);
        ll total = 0;
        for(int i = 0; i < k;++i){
            ++g1[nums1[i]];
            ++g2[nums2[i]];
            ++total;
        }
        ll ans = 0;
        for(auto &va:g1)
            ans += (va.second)*(total-va.second);
        ans >>= 1;
        for(auto &va:g2)
            ans -= ((va.second*(va.second-1))>>1);
        printf("%lld\n",ans);
    }
    return 0;
}
