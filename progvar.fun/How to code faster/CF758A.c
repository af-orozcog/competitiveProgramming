#include<stdio.h>
#define max(x,y)(x > y? x:y)

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    int ma = -1;
    for(int i = 0; i < n;++i)
        ma = max(ma,nums[i]);
    int ans = 0;
    for(int i = 0; i < n;++i)
        ans += ma-nums[i];
    printf("%d\n",ans);
    return 0;
}
