#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> nums;


bool add(int val, int upTo){
    return nums[val].size() == 0 || nums[val].back() < upTo;
}


int main(){
    nums.resize(100001);
    int n;
    scanf(" %d",&n);
    for(int i = 0; i < n;++i){
        int x,y;
        scanf(" %d %d",&x,&y);
        int upTo = sqrt(x);
        vector<int> toAdd;
        int ans = 0;
        for(int j = 1; j <= upTo;++j){
            if(x % j == 0){
                toAdd.push_back(j);
                ans += add(j,i-y);
                if(x/j != j){
                    toAdd.push_back(x/j);
                    ans += add(x/j,i-y);
                }
            }
        }
        for(auto va:toAdd)
            nums[va].push_back(i);
        printf("%d\n",ans);
    }
    return 0;
}
