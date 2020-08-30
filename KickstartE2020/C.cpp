#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

ll check(vector<pi> see){
    ll ans = 0;
    for(auto va:see)
        ans += va.first;
    ll temp = 0;
    for(int i = 0; i < see.size();++i){
        if(ans - see[i].first < see[i].second){
            ans = max(ans,temp+ans);
            return ans;
        }
        temp += see[i].first;
    }
    return -1;
}

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        pi nums[n];
        for(int i = 0; i < n;++i)
            scanf(" %lld %lld",&nums[i].first,&nums[i].second);
        ll ans = 0;
        int mi = 0;
        for(int i = 1; i < (1<<n);++i){
            int temp = i;
            int ind = 0;
            vector<pi> send;
            while(temp){
                if(temp&1) send.push_back(nums[ind]);
                ++ind;
                temp = temp >>1;
            }
            ll comp = check(send);
            if(comp == -1)
                ans = -1,mi = max(mi,(int)send.size());
            else if(comp > ans && ans != -1)
                ans = comp,mi = send.size();
            else if(comp == ans)
                mi = max((int)send.size(),mi);
        }
        printf("Case #%d: ",cas++);
        if(ans == -1)
            printf("%d INDEFINITELY\n",n-mi);
        else
            printf("%d %lld\n",n-mi,ans);
    }
    return 0;
}
