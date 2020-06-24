#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int from = (n>>1)+(n&1);
        int imp = from*451;
        //cout << imp << " " << from << "\n";
        int dp[from][imp];
        --from;
        memset(dp,0,sizeof(dp));
        int sum = 0;
        for(int i = 0; i < n;++i){
            int va; scanf("%d",&va);
            for(int j = from; j > 0;--j){
                for(int k = 0; k < imp;++k){
                    if(k - va < 0) continue;
                    dp[j][k] = (dp[j][k]) | (dp[j-1][k-va]);
                }
            }
            dp[0][va] = 1;
            sum += va;
        }
        int ans = 1000000000;
        int who;
        for(int i = 0;i < imp;++i){
            if(dp[from][i]){
                int ot = sum - i;
                if(abs(ot-i) < ans)
                    ans = abs(ot-i), who = i;
            }
        }
        printf("%d %d\n",min(sum-who,who),max(who,sum-who));
        if(t != 0) puts("");
    }
    return 0;
}
