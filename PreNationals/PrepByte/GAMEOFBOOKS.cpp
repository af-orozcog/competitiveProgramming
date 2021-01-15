#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int mi = INT_MAX;
        map<int,int> nums;
        for(int i = 0; i < n;++i){
            int va;
            scanf(" %d",&va);
            ++nums[va];
            mi = min(mi,va);
        }
        ll ans = 0;
        ll now = 0;
        for(auto it = nums.rbegin(); it != nums.rend();++it){
            if((*it).first == mi) break;
            int important = (*it).second;
            now += (ll)important;
            ans += now;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
