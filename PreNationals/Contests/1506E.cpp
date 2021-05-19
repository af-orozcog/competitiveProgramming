#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        set<int> big,smol;
        int nums[n];
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            big.insert(i+1);
            smol.insert(i+1);
        }
        int ans1[n];
        int ans2[n];
        for(int i = 0; i < n;++i){
            if(big.count(nums[i])){
                ans2[i] = nums[i];
                big.erase(nums[i]);
            }
            else{
                auto use = big.lower_bound(nums[i]);
                --use;
                ans2[i] = *use;
                big.erase(use);
            }
            if(smol.count(nums[i])){
                ans1[i] = nums[i];
                smol.erase(nums[i]);
            }
            else{
                ans1[i] = *(smol.begin());
                smol.erase(smol.begin());
            }
        }

        for(int i = 0; i < n;++i) printf("%d ",ans1[i]);
        puts("");
        for(int i = 0; i < n;++i) printf("%d ",ans2[i]);
        puts("");
    }
    return 0;
}
