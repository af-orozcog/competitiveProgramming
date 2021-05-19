#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

using namespace std;

int gcd(int a, int b){
    return b == 0? a: gcd(b,a%b);
}

void dele(map<int,int> &mp, set<pi> &bad, pi del){
    mp.erase(del.second);
    auto next = mp.lower_bound(del.second+1);
    if(next == mp.end()) next = mp.begin();
    int see = next->first;
    bad.erase(del);
    bad.erase({del.second,see});
    if(gcd(mp[del.first],mp[see]) == 1)
        bad.insert({del.first,see});
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        map<int,int> mp;
        set<pi> bad;
        vector<int> ans;
        for(int i = 0; i < n;++i){
            int va; scanf(" %d",&va);
            mp[i] = va;
        }
        for(int i = 0; i < n;++i){
            int next = i+1;
            if(next >= n) next -= n;
            if(gcd(mp[i],mp[next]) == 1)
                bad.insert({i,next});
        }
        int see = 0;
        while(bad.size()){
            auto del = bad.lower_bound({see,0});
            if(del == bad.end()) del = bad.begin();
            pi toDel = *del;
            dele(mp,bad,toDel);
            see = toDel.second;
            ans.push_back(toDel.second);
        }

        printf("%d",(int)ans.size());
        for(auto va: ans)
            printf(" %d",va+1);
        puts("");
    }
    return 0;
}
