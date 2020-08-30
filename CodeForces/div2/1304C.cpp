#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,pair<ll,ll>> pii;
typedef pair<ll,ll> pi;


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;ll m;
        scanf(" %d %lld",&n,&m);
        vector<pii> important;
        bool posi = 1;
        for(int i = 0; i < n;++i){
            ll t,l,h;
            scanf(" %lld %lld %lld",&t,&l,&h);
            if(!important.size() || important.back().first != t)
                important.push_back({t,{l,h}});
            else{
                important.back().second.first = max(important.back().second.first,l);
                important.back().second.second = min(important.back().second.second,h);
            }
            if(important.back().second.first > important.back().second.second)
                posi = 0;
        }
        if(!posi){puts("NO");continue;}
        for(int i = important.size()-1; i > 0 && posi;--i){
            if(important[i].second.first > important[i].second.second)
                posi = 0;
            if(important[i-1].second.second > important[i].second.second){
                ll neHigh = important[i].first - important[i-1].first + important[i].second.second;
                important[i-1].second.second = min(important[i-1].second.second,neHigh);
            }
            if(important[i-1].second.first < important[i].second.first){
                ll neHigh = important[i].second.first - (important[i].first - important[i-1].first);
                important[i-1].second.first = max(important[i-1].second.first,neHigh);
            }
        }
        if(important[0].second.first > important[0].second.second)
            posi = 0;
        if((m < important[0].second.first && abs(important[0].second.first-m)>important[0].first)) posi = 0;
        if((m > important[0].second.second && abs(important[0].second.second-m)>important[0].first)) posi = 0;
        if(!posi) puts("NO");
        else puts("YES");
    }
    return 0;
}
