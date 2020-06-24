#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    int ca = 1;
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        int ans = 0;
        for(int i = 0; i <= n-k;++i){
            bool add = 1;
            for(int j = k,q = 0; j > 0 && add;--j,++q)
                add = add &(nums[i+q] == j);
            if(add) ++ans;
        }
        printf("Case #%d: %d\n",ca++,ans);
    }
    return 0;
}
