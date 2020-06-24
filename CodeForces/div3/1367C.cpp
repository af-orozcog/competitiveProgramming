#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        vector<int> nums;
        nums.push_back(-k-1);
        for(int i = 0; i < n;++i){
            char va;
            scanf(" %c",&va);
            if(va == '1')nums.push_back(i);
        }
        nums.push_back(n+k);
        int ans = 0;
        for(int i = 0; i < nums.size()-1;++i){
            int where = nums[i];
            while(where + k + 1 <= nums[i+1] - k - 1 && where + k + 1 < n){
                ++ans;
                where += k + 1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
