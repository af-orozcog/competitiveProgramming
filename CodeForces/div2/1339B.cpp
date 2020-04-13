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
        sort(nums,nums+n);
        int ans[n];
        int i = 0,j = n-1;
        int turn = 1;
        int k = n-1;
        while(k > -1){
            if(turn) ans[k--] = nums[j--];
            else ans[k--] = nums[i++];
            turn = (turn+1)&1;
        }
        for(int i = 0; i < n;++i)printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
