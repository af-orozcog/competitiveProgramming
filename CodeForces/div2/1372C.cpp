#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

bool totalDisorder(int nums[],int l, int r){
    if(l > r) return true;
    for(int i = l; i <= r;++i){
        if(nums[i-1] == i) return false;
    }
    return true;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        int ordered = 1;
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            ordered = ordered & (nums[i] == i+1);
        }
        int ans = 100;
        if(ordered) ans = min(ans,0);
        else if(totalDisorder(nums,1,n))
            ans = min(ans,1);
        else{
            ans = min(ans,2);
            int longestOrderedPre = 0;
            int longestOrderedPos = n-1;
            while(nums[longestOrderedPre] == longestOrderedPre+1)
                ++longestOrderedPre;
            while(nums[longestOrderedPos] == longestOrderedPos+1)
                --longestOrderedPos;
            if(totalDisorder(nums,longestOrderedPre+1,n))
                ans = min(ans,1);
            //cout << longestOrderedPos << "\n";
            if(totalDisorder(nums,1,longestOrderedPos+1))
                ans = min(ans,1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
