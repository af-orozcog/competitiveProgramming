#include<stdio.h>
#define max(x,y)(x > y? x:y)

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    int nums[n];
    for(int i = 0; i < n;++i)
        scanf(" %d",&nums[i]);
    int ans = 0;
    for(int i = 1; i < n;++i){
        int add = max(0,k-(nums[i]+nums[i-1]));
        nums[i] += add;
        ans += add;
    }
    printf("%d\n",ans);
    for(int i = 0; i < n;++i) printf("%d ",nums[i]);
    puts("");
    return 0;
}
