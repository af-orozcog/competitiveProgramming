#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastSum(ll n){
    return (n *(n+1ll))>>1;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        ll ans = 0;
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            if(nums[i]%2 == 0 && (nums[i]>>1)%2 == 0)
                ++ans;
        }
        int last1 = -1,last2 = -1;
        int who1,who2;
        int tama = n;
        ll add = 0;
        for(int i = n-1; i > -1;--i){
            ans += add;
            if(nums[i] == 0){
                ans += tama - (i+1);
                add += tama - i;
                last1 = last2 = -1;
                tama = i;
                continue;
            }
            if(nums[i]%2 == 0){
                if((nums[i]>>1)%2 == 0)
                    ans += tama - (i+1);
                else if(last1 != -1)
                    ans += tama-last1;
            }
            if((nums[i]&1)){
                if(last1 != -1 && (who1>>1)%2 == 0)
                    ans += tama-last1;
                else if(last2 != -1)
                    ans += tama - last2;
            }
            if(nums[i]%2 == 0) last2 = last1,last1 = i,who2 = who1,who1 = nums[i];
        }
        for(int i = 0; i < n;++i){
            int tama = 0;
            while(i < n && (nums[i]&1))
                ++i,++tama;
            ans += fastSum(tama);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
