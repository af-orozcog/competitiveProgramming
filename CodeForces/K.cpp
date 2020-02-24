#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    ll nums[n];
    for(int i = 0; i < n;++i) scanf(" %lld",&nums[i]);
    sort(nums,nums+n);
    if(nums[0] != 1ll){puts("1");return 0;}
    bool ans = 0;
    ll co = 0;
    for(ll i = 0; i < n-1 && !ans;++i){
        co += nums[i];
        ll dif = nums[i+1]-nums[i];
        if(dif-1 > co-(nums[i])){
            printf("%lld\n",co+1ll);
            ans = 1;
        }
    }
    if(!ans)
        printf("%lld",co+1);
    return 0;
}
