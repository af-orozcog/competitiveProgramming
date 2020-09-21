#include<stdio.h>
#include<string.h>

int main(){
    int dp[3] = {0};
    char see[200];
    scanf(" %s",see);
    int n = strlen(see);
    for(int i = 0; i < n;++i){
        if(see[i] == 'A')
            dp[1] += dp[0];
        if(see[i] == 'Q'){
            dp[2] += dp[1];
            ++dp[0];
        }
    }
    printf("%d\n",dp[2]);
    return 0;
}
