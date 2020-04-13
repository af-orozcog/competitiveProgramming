#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

void shitty(set<pi> &shit,pi del){
    vector<pi> toDel;
    for(auto va:shit){
        if(va.first <= del.first && va.second <= del.second) toDel.push_back(va);
        else if(va.first > del.first && va.second > del.second) break;
    }
    //cout << "tama " <<toDel.size() << "\n";

    for(auto va:toDel)
        shit.erase(va);
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        pii nums[n];
        set<pi> shit;
        for(int i = 0; i < n;++i){
            scanf(" %d %d %d",&nums[i].first,&nums[i].second.first,&nums[i].second.second);
            shit.insert(nums[i].second);
        }
        sort(nums,nums+n);
        int good = 0;
        for(int i = n-1; i > -1;--i){
            pi see = nums[i].second;
            if(shit.count(see)){
      //          cout <<nums[i].first <<" "<<see.first << " " <<see.second << endl;
                ++good;
                shitty(shit,see);
            }
        }
        printf("%d\n",good);
    }
    return 0;
}
