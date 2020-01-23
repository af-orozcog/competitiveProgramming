#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
string A,B;
int solve(int i,int j, int p1, int p2){
    if(i < 0 || j < 0) return 0;
    if(p1 < 0 || p2 < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] = 0;
    for(int l = p1,m = p2; l > -1 && m > -1;--l,++m){
        if(A[l] != B[m]){
            dp[i][j] += max(solve(i-1,j,l-1,m),solve(i,j-1,l,m-1));
            break;
        }
        ++dp[i][j];
    }
    return dp[i][j];
}

int main(){
    cin >> A >> B;
    memset(dp,-1,sizeof(dp));
    int va = solve(1000,1000,A.size()-1,A.size()-1);
    cout << va << endl;
    if(va*100 >= (int)A.size()*99) puts("Long lost brothers D:");
    else puts("Not brothers :(");
}
