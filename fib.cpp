#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[100000];

ll fib(int n){
    if(dp[n] != -1) return dp[n];
    if(n == 0 || n == 1) return 1ll;
    return dp[n] = (fib(n-1) + fib(n-2));
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    scanf(" %d",&n);
    printf("%lld\n",fib(n));
}
