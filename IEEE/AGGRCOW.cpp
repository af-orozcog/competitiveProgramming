#include<bits/stdc++.h>
using namespace std;

int nums[100002];

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,c;
        scanf(" %d %d",&n,&c);
        for(int i = 0; i < n;++i)
            scanf(" %d",&nums[i]);
        sort(nums,nums+n);
        int ans = 1, lo = 0, hi = 1000000000;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            int co = c;
            int last = nums[0];
            --co;
            for(int i = 1; i < n && co;++i)
                if(nums[i] - last >= mid) --co,last = nums[i];
            if(co == 0){
                ans = mid;
                lo = mid +1;
            }
            else hi = mid - 1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
