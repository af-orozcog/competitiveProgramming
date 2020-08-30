#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string lel;
        cin >> lel;
        vector<vector<int>> dp(10,vector<int> (lel.size(),0));
        int ans = (int)lel.size()-2;
        int amount[10];
        memset(amount,0,sizeof(amount));
        int ma = 0;
        for(int i = 0; i < lel.size();++i){
            ++amount[lel[i]-'0'];
            ma = max(amount[lel[i]-'0'],ma);
            dp[lel[i]-'0'][i] = 1;
            for(int j = 0; j <= 9;++j){
                if(i == 0)break;
                dp[j][i] += dp[j][i-1];
            }
        }
        ans = min(ans,(int)lel.size()-ma);
        for(int i = 0; i < 10;++i){
            for(int j = 0; j < 10;++j){
                if(j == i) continue;
                int temp = 0;
                int ri = (int)lel.size()-1;
                for(int k = (int)lel.size()-1; k > -1;--k){
                    if(lel[k]-'0' == i){
                        if(dp[j][ri]-dp[j][k])
                            temp += ri-k-1;
                        else
                            temp += ri-k+1;
                        ri = k-1;
                    }
                }
                if(ri != -1)
                    temp += ri+1;
                ans = min(ans,temp);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
