#include<bits/stdc++.h>
#define ll long long
using namespace std;


int dp[302][302][602];
int matrix[301][301];

int n;

int solve(int x1,int x2,int dist){
    int y1 = dist-x1, y2 = dist-x2;
    if(x1 >= n || y1 >= n || x2 >= n || y2 >= n) return -1000000000;
    if(x1 == x2 && x1 == n-1 && y1 == n-1)
        return matrix[n-1][n-1];
    if(dp[x1][x2][dist] != -1)
        return dp[x1][x2][dist];
    int ans = 0;
    if(x1 !=  x2 || y1 != y2)
        ans += matrix[x1][y1] + matrix[x2][y2];
    else
        ans += matrix[x1][y1];
    int add = -1000000000;
    add = max(add,solve(x1,x2,dist+1));
    add = max(add,solve(x1,x2+1,dist+1));
    add = max(add,solve(x1+1,x2,dist+1));
    add = max(add,solve(x1+1,x2+1,dist+1));
    return dp[x1][x2][dist] = add+ans;
}


int main(){
    memset(dp,-1,sizeof(dp));
    scanf(" %d",&n);
    for(int i = 0; i < n;++i)
        for(int j = 0; j < n;++j)
            scanf(" %d",&matrix[i][j]);
    printf("%d\n",solve(0,0,0));
    return 0;
}
