#include<bits/stdc++.h>
using namespace std;

int dp[100][51][51];
int ar[100];
int n;

int solve(int p, int e,int o, int last){
    if(p == n) return 0;
    if(dp[p][e][o] != -1) return 0;
    if(ar[p]) dp[p][e][o] = (last%2 != ar[p]%2) + solve(p+1,e,o,ar[p]);
    else{
        if(e == 0)
            dp[p][e][o] = (last%2 != 1 && p != 0) + solve(p+1,e,o-1,1);
        else if(o == 0)
            dp[p][e][o] = (last%2 != 0 && p != 0) + solve(p+1,e-1,o,0);
        else
            dp[p][e][o] = min((last%2 != 1 && p != 0) + solve(p+1,e,o-1,1), (last%2 != 0 && p != 0) + solve(p+1,e-1,o,0));
    }
    return dp[p][e][o];
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf(" %d",&n);
    int odd, eve;
    odd = eve = 0;
    for(int i = 0; i < n;++i){
        scanf(" %d",&ar[i]);
        if(ar[i]&1) ++odd;
        else if(ar[i]) ++eve;
    }
    eve = (n>>1)- eve; odd = (n>>1) + (n&1) - odd;
    //cout << eve << " " << odd << endl;
    printf("%d\n",solve(0,eve,odd,ar[0]));
    return 0;
}
