#include<bits/stdc++.h>
using namespace std;


int n,k;
int dp[802][4002];
int p[802][4000];

int matrix[4002][4002];

int cost(int i, int j){
    if(i > j) return 0;
    int ans = 0;
    for(int k = j; k >= i;--k)
        ans += matrix[k][k] - matrix[k][i-1];
    return ans;
}

void pre(){
    for(int i = 0; i <= n;++i){
        for(int j = 1; j <= n;++j)
            matrix[i][j] += matrix[i][j-1];
    }
}


void fill(int g, int l1,int l2, int p1, int p2){
    if(l1 > l2) return;

    int mid = (l1+l2)>>1;
    p[g][mid] = -1;
    dp[g][mid] = 1000000000;
    for(int i = p1; i <= p2;++i){
        int com = dp[g-1][i] + cost(i+1,l2);
        if(com < dp[g][mid])
            dp[g][mid] = com,p[g][mid]   = i;
    }
    fill(g,l1,mid-1,p1,p[g][mid]);
    fill(g,mid+1,l2,p[g][mid],p2);
}

int main(){
    scanf(" %d %d",&n,&k);
    for(int i = 1; i <= n;++i)
        for(int j = 1; j <= n;++j) scanf(" %d",&matrix[i][j]);
    pre();
    for(int i = 0; i <= n;++i){
        dp[1][i] = cost(1,i);
        printf("%d ",dp[1][i]);
        p[1][i] = 0;
    }
    puts("");
    for(int i = 2; i <= k;++i)
        fill(i,0,n,0,n);
    printf("%d\n",dp[k][n]);
    return 0;
}
