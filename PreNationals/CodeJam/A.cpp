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
        for(int i = 0; i < n-1;++i){
            int where = i;
            for(int j = where; j < n;++j){
                if(nums[j] < nums[where])
                    where = j;
            }
            ans += (where-i+1);
            reverse(nums+i,nums+where+1);
        }

        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
