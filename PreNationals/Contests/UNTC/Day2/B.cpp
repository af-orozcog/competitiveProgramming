#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int nums1[n],nums2[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums1[i]);
    for(int i = 0; i < n;++i) scanf(" %d",&nums2[i]);
    sort(nums1,nums1+n);
    sort(nums2,nums2+n);
    int ans = 0;
    for(int i = 0; i < n;++i){
        int where = lower_bound(nums2,nums2+n,nums1[i])-nums2;
        if(where == n) --where;
        int va = abs(nums2[where]-nums1[i]);
        if(where != 0)
            va = min(abs(nums1[i]-nums2[where-1]),va);
        ans = max(ans,va);
    }
    printf("%d\n",ans);
    return 0;
}
