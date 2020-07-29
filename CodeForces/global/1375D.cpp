#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        set<int> mex;
        int n;
        scanf(" %d",&n);
        for(int i = 0; i <=n;++i)
            mex.insert(i);
        int nums[n];
        int ordered = 1;
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            if(nums[i] != nums[i-1]) ordered = 0;
            mex.erase(nums[i]);
        }
        vector<int> operations;
        if(*(mex.begin()) == n && !ordered){
            operations.push_back(n);
            int temp = nums[n-1];
            mex.insert(temp);
            mex.erase(n);
        }
        while(*(mex.begin()) < n){
            int next = *(mex.begin());
            int temp = nums[next];
            nums[next] = next;
            operations.push_back(next);
            mex.insert(temp);
            mex.erase(next);
        }
        printf("%d\n",(int)operations.size());
        for(auto va:operations)
            printf("%d ",va);
        puts("");
    }
    return 0;
}
