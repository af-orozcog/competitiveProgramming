#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int dp1[1000];
int dp2[1000];

int main(){
    pair<int,pi> nums[1000];
    int n = 0;
    while(scanf(" %d %d",&nums[n].first,&nums[n].second.first) == 2)
        nums[n].second.second = n,++n;
    sort(nums,nums+n);
    dp1[0] = 1;
    int ans = 0;
    int who;
    for(int i = 1; i < n;++i){
        dp1[i] = 1;
        dp2[i] = i+1;
        for(int j = i-1; j > -1;--j){
            if(nums[i].first > nums[j].first && nums[i].second.first < nums[j].second.first){
                if(dp1[j] + 1 > dp1[i])
                    dp1[i] = dp1[j] +1, dp2[i] = j+1;
            }
        }
        if(ans < dp1[i]) ans = dp1[i],who = i+1;
    }
    printf("%d\n",ans);
    int co = ans;
    int vals[ans];
    while(ans--){
       // printf("%d %d\n",nums[who-1].first,nums[who-1].second);
        vals[ans] = nums[who-1].second.second;
        who = dp2[who-1];
    }
    for(int i = 0; i < co;++i) printf("%d\n",vals[i]+1);
    return 0;
}
