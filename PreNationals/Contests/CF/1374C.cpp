#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

vector<pair<int,int>> answer(map<int,int> use,int n, int skip){
    vector<pair<int,int>> show;
    int skipped = skip;
    int important;
    int last = (*use.rbegin()).first;
    --use[last];
    if(use[last] == 0)
        use.erase(last);
    important = last;
    while(show.size() != n-1){
        int now = (*use.rbegin()).first;
        int needed = last - now;
        --use[now];
        if(use[now] == 0) use.erase(now);
        if(use.count(needed)){
            --use[needed];
            if(use[needed] == 0)
                use.erase(needed);
            show.push_back({now,needed});
            last = now;
        }
        else{
            if(skipped != -1) break;
            skipped = now;
        }
    }

    if(show.size() != n-1){
        vector<pair<int,int>> lel;
        return lel;
    }
    if(skipped == -1)
        skipped = (*use.begin()).first;
    show.insert(show.begin(),{skipped,important});
    return show;
}


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[2*n];
        map<int,int> seen;
        for(int i = 0; i < 2*n;++i){
            scanf(" %d",&nums[i]);
            ++seen[nums[i]];
        }
        sort(nums,nums+2*n);
        vector<pair<int,int>> moves = answer(seen,n,-1);
        for(int i = 2*n-2;i > -1 && moves.size() != n;--i){
            --seen[nums[i]];
            if(seen[nums[i]] == 0)
                seen.erase(nums[i]);
            moves = answer(seen,n,nums[i]);
            ++seen[nums[i]];
        }
        if(moves.size() != n){
            puts("NO");
            continue;
        }
        puts("YES");
        printf("%d\n",moves[0].first+moves[0].second);
        for(auto &va:moves)
            printf("%d %d\n",va.first,va.second);
    }
    return 0;
}
