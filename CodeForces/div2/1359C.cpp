#include<bits/stdc++.h>
using namespace std;

int dp[202][513];

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    int a[n],b[m];
    for(int i = 0; i < n;++i)
        scanf(" %d",&a[i]);
    for(int i = 0; i < m;++i)
        scanf(" %d",&b[i]);
    dp[0][0] = 1;
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j){
            int val = a[i]&b[j];
            for(int k = 0; k <= 512;++k){
                if(dp[i][k])
                    dp[i+1][k|val] = 1;
            }
        }
    }
    int ans = 512;
    for(int i = 0; i < 512 && ans == 512;++i)
        if(dp[n][i])
            ans = i;
    printf("%d\n",ans);
    return 0;
}
