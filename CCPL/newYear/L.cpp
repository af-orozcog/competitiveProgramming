#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    while(scanf(" %d %d",&n,&k) == 2){
        int nums[(n*k)<<1];
        int siz = (n*k)<<1;
        for(int i = 0; i < siz;++i) scanf(" %d",&nums[i]);
        sort(nums,nums+siz);
        int lo = nums[1]-nums[0],hi = nums[siz-1]-nums[0], ans;
        while(lo<=hi){
            int mid = (lo+hi)>>1;
            int co = 0,need = 0;
            for(int i = 0; i < siz-1 && need >= 0;++i){
                if(co == n) {--need;continue;}
                else if(nums[i+1] - nums[i] <= mid){
                    ++co; need += (k<<1)-2,++i;
                }
                else --need;
            }
            if(need < 0 || co != n)
                lo = mid +1;
            else
                hi = mid -1,ans = mid;
        }
        printf("%d\n",ans);
    }
    return 0;
}
