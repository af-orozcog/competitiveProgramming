#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll M = 1000000007;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        ll nums[n];
        for(int i = 0; i < n;++i)scanf(" %lld",&nums[i]);
        sort(nums,nums+n);
        reverse(nums,nums+n);
        ll ans = 0;
        ll less = 0;
        for(int i = 0;i < n;++i){
            ans += max(nums[i]-less,(ll)0);
            ++less;
            if(ans >= M)
                ans -= M;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
