#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int n;
    scanf(" %d",&n);
    ll nums[n];
    for(int i = 0; i < n;++i) scanf(" %lld",&nums[i]);
    vector<pi> st;
    ll ans = 0;
    for(int i = 0; i < n;++i){
        while(st.size() && st.back().second > nums[i]){
            pi see = st.back();
            st.pop_back();
            ll left;
            if(st.size()) left = st.back().first;
            else left = -1;
            ans = max(ans,see.second*(i-left-1));
        }
        st.push_back({i,nums[i]});
    }
    while(st.size()){
        pi see = st.back();
        st.pop_back();
        ll left;
        if(st.size()) left = st.back().first;
        else left = -1;
        ans = max(ans,see.second*(n-left-1));
    }
    printf("%lld\n",ans);
    return 0;
}
