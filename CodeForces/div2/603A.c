#include<stdio.h>
#define max(x,y)(x > y? x:y)

int main(){
    int n;
    scanf(" %d",&n);
    char see[n+1];
    scanf(" %s",see);
    int dp1[2][n],dp2[2][n];
    int ans = 0;
    if(see[0] == '1')
        dp1[1][0] = 1,dp1[0][0] = 0;
    else
        dp1[1][0] = 0,dp1[0][0] = 1;
    for(int i = 1; i < n;++i){
        if(see[i] == '1')
            dp1[1][i] = dp1[0][i-1] +1,dp1[0][i] = dp1[0][i-1];
        else
            dp1[0][i] = dp1[1][i-1] + 1,dp1[1][i] = dp1[1][i-1];
        ans = max(ans,dp1[0][i]);
        ans = max(ans,dp1[1][i]);
    }
    if(see[n-1] == '1')
        dp2[1][n-1] = 1,dp2[0][n-1] = 0;
    else
        dp2[1][n-1] = 0,dp2[0][n-1] = 1;
    for(int i = n-2; i > -1;--i){
        if(see[i] == '1')
            dp2[1][i] = dp2[0][i+1] + 1,dp2[0][i] = dp2[0][i+1];
        else
            dp2[0][i] = dp2[1][i+1] + 1,dp2[1][i] = dp2[1][i+1];
        ans = max(ans,dp2[0][i]);
        ans = max(ans,dp2[1][i]);
    }
    if(n < 3){
        if(n == 1) puts("1");
        else puts("2");
        return 0;
    }
    ans = max(ans,3);
    int le = 0;
    for(int i = 1; i < n;){
        while(i < n && see[i] != see[i-1]) ++i;
        int pos2;
        if(le == 0 && i == n) continue;
        if(le == 0) pos2 = dp2[see[i-1]-'0'][i];
        else if(i == n) pos2 = dp1[see[le]-'0'][le-1];
        else
            pos2 = dp1[see[le]-'0'][le-1]+ dp2[see[i-1]-'0'][i];
        ans = max(ans,i-le+pos2);
        ++i;
        le = i-1;
    }
    printf("%d\n",ans);
    return 0;
}
