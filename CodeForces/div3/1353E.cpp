//hope to have a good performance to show Marie :)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        vector<int> inde;
        char imp[n+1];
        scanf(" %s",imp);
        for(int i = 0; i < n;++i)
            if(imp[i] == '1') inde.push_back(i);
        int ans = (int)inde.size();
        vector<int> dp(n);
        dp[n-1] = 0;
        for(int i = n-2; i > -1;--i){
            if(i + k >= n) {
                int ind1 = lower_bound(inde.begin(),inde.end(),i+1)-inde.begin();
                dp[i] = (int)inde.size()-ind1;continue;
            }
            int add1 = (imp[i] != '1');
            int ind1 = lower_bound(inde.begin(),inde.end(),i+1)-inde.begin();
            int add2 = (int)inde.size()-ind1;
            int ind2 = lower_bound(inde.begin(),inde.end(),i+k)-inde.begin();
            if(ind1 != (int)inde.size() && inde[ind1] == i+k) ind1 = ind2;
            dp[i] = min(dp[i+k] + add1 + (ind2-ind1),add2);
        }
        int acum = 0;
        for(int i = 0; i < n;++i){
            ans = min(ans,dp[i]+acum);
            if(imp[i] == '1') ++acum;
        }
        printf("%d\n",ans);
    }
    return 0;
}
