#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums){
    int sz = (int)nums.size()/3;

    for(int i = 0; i < sz;++i)
        if(nums[i]+nums[i+sz] != nums[i+sz+sz])
            return 0;
    return 1;
}


int main(){
    while(1){
        int n;
        scanf(" %d",&n);
        vector<int> nums;
        for(int i = 0; i < n*3;++i){
            nums.push_back(i+1);
        }
        int keep = 1;
        do{
            if(check(nums)){
                keep = 0;
                for(auto va:nums)
                    printf("%d ",va);
                puts("");
            }
        }while(next_permutation(nums.begin(),nums.end()) && keep);
        if(keep) puts("Not found");
    }
}
