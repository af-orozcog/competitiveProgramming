#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        vector<int> ans;
        ans.push_back(nums[n-1]);
        for(int i = n-2; i > 0;--i){
            if((nums[i] > nums[i+1] && nums[i] > nums[i-1]) || (nums[i] < nums[i+1] && nums[i] < nums[i-1]))
                ans.push_back(nums[i]);
        }
        ans.push_back(nums[0]);
        reverse(ans.begin(),ans.end());
        printf("%d\n",(int)ans.size());
        for(auto va: ans)
            printf("%d ",va);
        puts("");
    }
    return 0;
}
