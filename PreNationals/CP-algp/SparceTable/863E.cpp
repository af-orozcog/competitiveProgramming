#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

bool comp(const pair<pi,int> &a,const pair<pi,int> &b){
    if(a.first.first < b.first.first) return 1;
    if(b.first.first < a.first.first) return 0;
    return a.first.second > b.first.second;
}

int main(){
    int n;
    scanf(" %d",&n);
    pair<pi,int> nums[n];
    for(int i = 0; i < n;++i){
        nums[i].second = i;
        scanf(" %d %d",&nums[i].first.first,&nums[i].first.second);
    }
    sort(nums,nums+n,comp);
    int upTo = nums[0].first.second;
    int ans = -1;
    for(int i = 1; i < n && ans == -1;++i){
        if(nums[i].first.first <= upTo && nums[i].first.second <= upTo) ans = nums[i].second;
        if(i != n-1 && nums[i+1].first.first - upTo <= 1 && nums[i].first.second <= nums[i+1].first.second) ans = nums[i].second;
        upTo = max(nums[i].first.second,upTo);
    }
    if(ans != -1) ++ans;
    printf("%d\n",ans);
    return 0;
}
