#include<bits/stdc++.h>
using namespace std;

int nums[1000000];
int big[1000000];

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            if(i)
                big[i] = max(big[i-1],nums[i]);
            else
                big[i] = nums[i];
        }
        int ans = 0;
        for(int i = 0; i < n;++i){
            if(i == 0 && i == n-1) ++ans;
            else if(i == 0 && nums[i+1] < nums[i]) ++ans;
            else if(i == n-1 && big[i-1] < nums[i]) ++ans;
            else if(big[i-1] < nums[i] && nums[i+1] < nums[i]) ++ans;
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
