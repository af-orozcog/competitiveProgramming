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
        map<int,vector<ll>> mp;
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        vector<ll> ans(n+1,0);
        for(int i = 0; i < n;++i){
            ll temp; scanf(" %lld",&temp);
            mp[nums[i]].push_back(temp);
        }
        for(auto &see:mp){
            sort(see.second.begin(),see.second.end());
            for(int i = 1; i < see.second.size();++i) see.second[i] += see.second[i-1];
            for(int i = 1; i <= see.second.size();++i){
                int r = (int)see.second.size() % i;
                ans[i] += see.second[see.second.size()-r-1];
            }
        }
        for(int i = 1; i < ans.size();++i) printf("%lld ",ans[i]);
        puts("");
    }
    return 0;
}
