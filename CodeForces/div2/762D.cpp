#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[3][3][3][100002];
bool visited[3][3][3][100002];
ll matrix[3][100002];
int N;

ll solve(int p, int l,int u,int k){
    if(p == 2 && k == N-1) return matrix[p][k];
    if(visited[p][l][u][k]) return dp[p][l][u][k];
    visited[p][l][u][k] = 1;
    dp[p][l][u][k] = matrix[p][k];
    ll temp = 0;
    if(k == N-1){
        temp = solve(p+1,0,u,k);
        if(p == 1 && u == 0)
            temp = max(temp,matrix[p][k-1] +matrix[p+1][k-1] + matrix[p+1][k]);
    }
    else if(p == 0 || p == 2){
        temp = solve(p,2,max(u-1,0),k+1);
        if(p == 0 && l != 0)
            temp = max(temp,solve(p+1,1,u,k));
        if(p == 2 && l != 1)
            temp = max(temp,solve(p-1,0,u,k));
    }
    else if(p == 1){
        temp = solve(p,2,2,k+1);
        if(l != 1) temp = max(temp,solve(p-1,0,2,k));
        if(l != 0) temp = max(temp,solve(p+1,1,2,k));
        if(u == 0 && k > 0){
            if(l == 0) temp = max(temp,solve(p-1,2,1,k+1)+matrix[p][k-1] +matrix[p-1][k-1] + matrix[p-1][k]);
            else if(l == 1) temp = max(temp,solve(p+1,2,1,k+1)+matrix[p][k-1] +matrix[p+1][k-1] + matrix[p+1][k]);
        }
    }
    dp[p][l][u][k] += temp;
    return dp[p][l][u][k];
}

int main(){
    scanf(" %d",&N);
    for(int i = 0; i < 3;++i){
        for(int j = 0; j < N;++j){
            int temp; scanf(" %d",&temp);
            matrix[i][j] = (ll)temp;
        }
    }
    cout << solve(0,2,0,0) << "\n";
    return 0;
}
