#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    ll nums1[n];
    ll nums2[m];
    for(int i = 0; i < n;++i){
        scanf(" %lld",&nums1[i]);
    }
    for(int i = 0; i < m;++i) scanf(" %lld",&nums2[i]);
    ll imp = 0;
    if(n > 1)
        imp = abs(nums1[1]-nums1[0]);
    for(int i = 2; i < n;++i){
        nums1[i] = abs(nums1[i]-nums1[0]);
        imp = __gcd(imp,nums1[i]);
    }
    for(int i = 0; i < m;++i)
        printf("%lld\n",__gcd(abs(nums1[0]+ nums2[i]),imp));
    return 0;
}
