#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k,z;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        scanf(" %d %d %d",&n,&k,&z);
        ll nums[n];
        for(int i = 0; i < n;++i)
            scanf(" %lld",&nums[i]);
        ll prefix[n];
        prefix[0] = nums[0];
        for(int i = 1; i < n;++i)
            prefix[i] = prefix[i-1]+nums[i];
        ll ans = 0;
        for(int i = 0; i < k;++i){
            ll temp = prefix[i];
            ll add1 = 0;
            ll add2 = 0;
            if(i){
                ll mi = min(k-(i),z<<1);
                add1 = (mi>>1)*(nums[i]+nums[i-1]);
                if(mi&1)
                    add1 += nums[i-1];
                else{
                    int to = k -(mi+i);
                    add1 += prefix[min(i+to,n-1)]-prefix[i];
                }
            }
            if(i != n-1){
                ll mi = min(k-(i),z<<1);
                add2 = (mi>>1)*(nums[i]+nums[i+1]);
                if(mi&1)
                    add2 += nums[i+1];
                else{
                    int to = k -(mi+i);
                    add2 += prefix[min(i+to,n-1)]-prefix[i];
                }
            }
            ans = max(ans,temp + max(add1,add2));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
