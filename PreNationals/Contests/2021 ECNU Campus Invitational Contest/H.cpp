#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pl;


int main(){
    int n;
    scanf(" %d",&n);
    vector<pl> nums(n);
    for(int i = 0; i < n;++i) scanf(" %lld %lld",&nums[i].first,&nums[i].second);
    vector<pair<ll,pl>> st;
    st.push_back({-1,{-1,-1}});
    ll ans = 0;
    for(int i = 0; i < n;++i){
        pl use = nums[i];
        while(st.back().second.first > use.first && st.back().second.second > use.second){ st.pop_back();}
        ans = max(ans,use.first*use.second*(i-st.back().first));
        st.push_back({i,use});
    }
    while(st.size() > 1){
        pair<ll,pl> now = st.back();
        pair<ll,pl> bef = st[st.size()-2];
        ans = max(ans,now.second.second*now.second.first*(now.first-bef.first));
        st.pop_back();
    }
    printf("%lld\n",ans);
    return 0;
}
