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
        bool posi = 0;
        int ans;
        for(int i = 1; i < n && !posi;++i){
            if(abs(nums[i]-nums[i-1]) > 1) posi = 1, ans = i;
        }
        if(posi) printf("YES\n%d %d\n",ans,ans+1);
        else puts("NO");
    }
    return 0;
}
