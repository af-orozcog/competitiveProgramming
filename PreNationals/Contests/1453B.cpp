#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        ll nums[n];
        for(int i = 0; i < n;++i) scanf(" %lld",&nums[i]);
        vector<ll> dif(n,0);
        for(int i = n-2; i > -1;--i)
            dif[i] = dif[i+1] + abs(nums[i]-nums[i+1]);
        ll ans = LLONG_MAX;
        for(int i = 0; i < n;++i){
            ll see = LLONG_MAX;
            if(i && i != n-1)
                see = min(see,dif[i+1] + abs(nums[i-1]-nums[i+1]) + dif[0] - dif[i-1]);
            else if(i == 0) see = min(see,dif[i+1]);
            else see = min(see,dif[0] - abs(nums[n-1]-nums[n-2]));
            ans = min(ans,see);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
