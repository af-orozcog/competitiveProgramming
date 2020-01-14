#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
string imp;

int solve(int i, int j){
    if(i == j) return 1;
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(imp[i] == imp[j]) dp[i][j] = 2 + solve(i+1,j-1);
    else dp[i][j] = max(solve(i+1,j),solve(i,j-1));
    return dp[i][j];
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        getline(cin,imp);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(0,imp.size()-1));
    }
    return 0;
}
