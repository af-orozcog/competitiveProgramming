#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        scanf(" %d",&n);
        ll odd[n],even[n],nums[n];
        memset(odd,0,sizeof(odd));
        memset(even,0,sizeof(even));
        for(int i = 0; i < n;++i){
            scanf(" %lld",&nums[i]);
            if(i&1)
                odd[i] += nums[i];
            else
                even[i] += nums[i];
            if(i)
                even[i] += even[i - 1], odd[i] += odd[i - 1];
        }
        ll ans = even[n-1];
        ll add = 0; int left = 0;
        for(int i = 1; i < n;i+=2){
            ll temp = odd[i];
            temp -= even[i];
            if(left) temp -= odd[left-1], temp += even[left-1];
            if(temp < 0ll)
                left = i+1;
            add = max(add,temp);
        }
        left = 1;
        for(int i = 2; i < n;i+=2){
            ll temp = odd[i];
            temp -= even[i];
            if(left) temp -= odd[left-1], temp += even[left-1];
            if(temp < 0ll)
                left = i+1;
            add = max(add,temp);
        }
        printf("%lld\n",ans+add);
    }
    return 0;
}
