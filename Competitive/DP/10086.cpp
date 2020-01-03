#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    bool fi = 1;
    while(1){
        int t1,t2;
        scanf(" %d %d",&t1,&t2);
        if(t1 == t2 && t1 == 0)return 0;
        if(!fi) puts("");
        fi = 0;
        int n; scanf(" %d",&n);
        vector<int> ms(n);
        vector<vector<int>> costs(n,vector<int> (t1+1,0));
        for(int i = 0; i < n;++i){
            scanf(" %d",&ms[i]);
            for(int j = 1; j <= ms[i];++j){
                int temp;scanf(" %d",&temp);
                if(j <= t1) costs[i][j] = temp;
            }
            for(int j = 1; j <= ms[i];++j){
                int temp;scanf(" %d",&temp);
                if(ms[i]-j <= t1) costs[i][ms[i]-j] += temp;
            }
        }
        vector<vector<int>> dp(n,vector<int> (t1+1,1000000000));
        int memo[n][t1+1];
        for(int i = 0; i <= t1;++i){
            if(ms[0]-i > t2 || ms[0]-i < 0) continue;
            dp[0][i] = costs[0][i];
        }
        int total = ms[0];
        for(int i = 1; i < n;++i){
            int lel;
            for(int j = 0; j <= t1;++j){
                if(total+ms[i]-j > t2) continue;
                for(int z = 0; z <= ms[i] && j-z > -1;++z){
                    if(dp[i-1][j-z]+costs[i][z] < dp[i][j]){
                        dp[i][j] = dp[i-1][j-z] + costs[i][z];
                        memo[i][j] = j-z;
                    }
                }
            }
            total += ms[i];
        }
        int va = 1000000000,who;
        for(int i = 0; i <= t1;++i){
            if(dp[n-1][i] < va){
                va = dp[n-1][i];who = i;
            }
        }
        vector<int> ans;
        for(int i = n-1,le = who; i > -1;--i){
            if(i == 0) ans.push_back(le);
            else{
            //    cout << memo[i][le] << endl;
             //   cout << dp[i-1][le] << endl;
                ans.push_back(le-memo[i][le]);
                le = memo[i][le];
            }
        }
        printf("%d\n",va);
        for(int i = ans.size()-1;i > -1;--i){
            if(i == 0) printf("%d\n",ans[i]);
            else printf("%d ",ans[i]);
        }
    }
    return 0;
}
