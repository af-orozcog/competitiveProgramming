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
        int ans = 1000000000;
        for(int i = 1; i < n;++i)
            ans = min(ans,nums[i]-nums[i-1]);
        printf("%d\n",ans);
    }
    return 0;
}
