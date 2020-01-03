#include<bits/stdc++.h>
using namespace std;
int dp[1025][1025];

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        memset(dp,0,sizeof(dp));
        int d,p; scanf(" %d %d",&d,&p);
        for(int i = 0; i < p;++i){
            int x,y,c;
            scanf(" %d %d %d",&x,&y,&c);
            dp[x][y] = c;
        }
        int anX,anY,big = -1;
        for(int i = 0; i < 1025;++i){
            for(int j = 0; j < 1025;++j){
                if(i != 0)
                    dp[i][j] += dp[i-1][j];
                if(j != 0)
                    dp[i][j] += dp[i][j-1];
                if(i != 0 && j != 0)
                    dp[i][j] -= dp[i-1][j-1];
                if(i - (d<<1) > -1 && j - (d<<1) > -1){
                    int see = dp[i][j];
                    if(i - (d<<1) > 0) see -= dp[i-(d<<1)-1][j];
                    if(j -(d<<1) > 0) see -= dp[i][j-(d<<1)-1];
                    if(i - (d<<1) > 0 && j-(d<<1) > 0) see +=dp[i-(d<<1)-1][j-(d<<1)-1];
                    int poX = i - d,poY = j - d;
                    if(see > big) anX = poX,anY = poY,big = see;
                    else if(see == big){
                        if(poX < anX)anX = poX,anY = poY,big = see;
                        else if(anX == poX && poY < anY)anX = poX,anY = poY,big = see;
                    }
                }
            }
        }
        printf("%d %d %d\n",anX,anY,big);
    }
    return 0;
}
