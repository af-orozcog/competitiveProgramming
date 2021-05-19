#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        sort(nums,nums+n);
        int ans = 0;
        for(int i = 1; i < n;++i){
            int check = k-nums[i];
            ans += max(0,check/nums[0]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
