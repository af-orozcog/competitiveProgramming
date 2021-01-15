#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    int nums[n];
    int ma = INT_MIN;
    int mi = INT_MAX;
    for(int i = 0; i < n;++i){
        scanf(" %d",&nums[i]);
        ma = max(nums[i],ma);
        mi = min(nums[i],mi);
    }
    if(k == 1)
        printf("%d\n",mi);
    else if(k == 2){
        int ans = INT_MIN;
        int le[n],ri[n];
        le[0] = nums[0];
        ri[n-1] = nums[n-1];
        for(int i = 1; i < n;++i)
            le[i] = min(nums[i],le[i-1]);
        for(int i = n-2; i > -1;--i)
            ri[i] = min(nums[i],ri[i+1]);
        for(int i = 0; i < n-1;++i)
            ans = max(ans,max(le[i],ri[i+1]));
        printf("%d\n",ans);
    }
    else printf("%d\n",ma);
    return 0;
}
