#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

short dp[101][101][10001];

int main(){
    dp[1][1][0] = 1;
    for(int i = 1; i < 101;++i){
        for(int j = 1; j < 101;++j){
            if(i == 1 && j == 1)continue;
            for(int k = 0; k < 10001;++k){
                if(j > 1 && k - i >= 0) dp[i][j][k] = dp[i][j][k] | dp[i][j-1][k-i];
                if(i > 1 && k -j >= 0) dp[i][j][k] = dp[i][j][k] | dp[i-1][j][k-j];
            }
        }
    }
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m,k;
        scanf(" %d %d %d",&n,&m,&k);
        if(dp[n][m][k]) puts("YES");
        else puts("NO");
    }

    return 0;
}
