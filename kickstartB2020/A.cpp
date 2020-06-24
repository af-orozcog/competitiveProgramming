#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        int ans = 0;
        for(int i = 1; i < n-1;++i)
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) ++ans;
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
