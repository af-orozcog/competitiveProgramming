#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int nums[] = {0,0};
    for(int i = 0; i < n;++i){
        int va;
        scanf(" %d",&va);
        ++nums[va&1];
    }
    int ans = 0;
    ans += min(nums[0],nums[1]);
    nums[1]-= ans;
    ans += nums[1]/3;
    printf("%d\n",ans);
    return 0;
}
