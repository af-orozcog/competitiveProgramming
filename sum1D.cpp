#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf( " %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    int ans = max(0,nums[0]);
    int sum = nums[0];
    for(int i = 1; i < n;++i){
        if(sum < 0)
            sum = 0;
        sum += nums[i];
        ans = max(ans,sum);
    }
    printf("%d\n",ans);
}
