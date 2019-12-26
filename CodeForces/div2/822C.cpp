#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,x;
    scanf(" %d %d",&n,&x);
    vector<pair<int,pair<int,int>>> nums(n);
    for(int i = 0; i < n;++i){
        int l,r,x;
        scanf(" %d %d %d",&l,&r,&x);
        nums[i] = {l,{r,x}};
    }
    sort(nums.begin(),nums.end());
    map<int,set<pair<int,int>>> fr;
    for(int i = n-1;i > -1;--i){
        int da = nums[i].second.first - nums[i].first +1;
        if(fr.count(da)){
            auto va = fr[da].begin();
            fr[da].insert({i,min((*va).second,nums[i].second.second)});
        }
        else
            fr[da].insert({i,nums[i].second.second});
    }
    int ans = 2000000001;
    for(int i = 0; i < n;++i){
        pair<int,pair<int,int>> le = {nums[i].second.first+1,{0,0}};
        int index = lower_bound(nums.begin(),nums.end(),le) - nums.begin();
        if(index == n) continue;
        int da = x- (nums[i].second.first - nums[i].first +1);
        if(fr.count(da)){
            pair<int,int> lu = {index,0};
            auto va = fr[da].lower_bound(lu);
            if(va == fr[da].end()) continue;
            ans = min(ans,nums[i].second.second + (*va).second);
        }
    }
    printf("%d\n",(ans == 2000000001?-1:ans));
    return 0;
}
