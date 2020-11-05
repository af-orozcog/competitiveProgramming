#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string see;
        cin >> see;
        int dp1[see.size()];
        int dp2[see.size()];
        int dp3[see.size()];
        int dp4[see.size()];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        memset(dp3,0,sizeof(dp3));
        memset(dp4,0,sizeof(dp4));
        int n = see.size();
        for(int i = 0; i < n;++i){
            dp1[i] = 1;
            if(i && see[i] == see[i-1])
                dp1[i] = 2;
            if(i && i-1-dp1[i-1] > -1 && see[i-1-dp1[i-1]] == see[i])
                dp1[i] = max(dp1[i],dp1[i-1]+2);
            dp3[i] = dp1[i];
            if(i) dp3[i] = max(dp3[i],dp3[i-1]);
        }
        for(int i = n-1; i > -1;--i){
            dp2[i] = 1;
            if(i != n-1 && see[i] == see[i+1])
                dp2[i] = 2;
            if(i != n-1 && i+1+dp2[i+1] < n && see[i+1+dp2[i+1]] == see[i])
                dp2[i] = max(dp2[i],dp2[i+1]+2);
            dp4[i] = dp2[i];
            if(i != n-1) dp4[i] = max(dp4[i],dp4[i+1]);
        }
        int ans = 0;
        for(int i = 0; i < n-1;++i)
            ans = max(ans,dp3[i]+dp4[i+1]);
        printf("%d\n",ans);
    }
    return 0;
}
