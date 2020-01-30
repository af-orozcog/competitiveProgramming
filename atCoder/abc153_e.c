#include<stdio.h>
#define min(x,y)(x < y? x:y)
#define max(x,y)(x > y? x:y)

int main(){
    int h,n;
    scanf(" %d %d",&h,&n);
    int dp[h+1];
    for(int i = 0; i < h+1;++i) dp[i] = 1000000000;
    dp[h] = 0;
    for(int i = 0; i < n;++i){
        int a,b;
        scanf("%d %d",&a,&b);
        for(int j = h; j > 0;--j)
            dp[max(0,j-a)] = min(dp[max(0,j-a)],dp[j]+b);
    }
    printf("%d\n",dp[0]);
    return 0;
}
