#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pl;


int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    ll vals[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    for(int i = 0; i < n;++i) scanf(" %lld",&vals[i]);
    vector<pl> st;
    ll dp[n];
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < n;++i){
        dp[i] = vals[i];
        while(st.size() && st.back().second > nums[i]){
            dp[i] = max(dp[i], vals[i] + dp[st.back().first]);
            st.pop_back();
        }
        if(st.size())
            dp[i] = max(dp[i],vals[i] + dp[st.back().first]);
        if(i)
            dp[i] = max(dp[i],dp[i-1]);
        st.push_back({i,nums[i]});
    }
    while(st.size()){
        pl use = st.back();
        st.pop_back();
        if(st.size())
            dp[n-1] = max(dp[n-1],vals[use.first] + dp[st.back().first]);
        else dp[n-1] = max(dp[n-1],vals[use.first]);
    }
    printf("%lld\n",dp[n-1]);
    return 0;
}
