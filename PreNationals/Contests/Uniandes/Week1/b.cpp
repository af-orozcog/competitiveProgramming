#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int n;
    scanf(" %d",&n);
    pi nums[n];
    for(int i = 0; i < n;++i) scanf(" %d %d",&nums[i].first,&nums[i].second);
    int ans = 0;
    for(int i = 0; i < n;++i){
        for(int j = i+1; j < n;++j){
            int part1 = abs(nums[j].second-nums[i].second);
            int part2 = abs(nums[j].first - nums[i].first);
            if(part1 <= part2) ++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}
