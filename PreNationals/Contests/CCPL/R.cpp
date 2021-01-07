#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll MOD = 1000000007;

int main(){
    int n;
    while(scanf(" %d",&n) == 1){
        char vals[n+1];
        scanf(" %s",vals);
        vector<vector<int>> nums(10);
        ll ans = 0;
        int fromLeft[10][n+1];
        int fromRight[10][n+2];
        for(int i = 0; i < 10; ++i)
            fromLeft[i][0] = 0;
        for(int i = 0; i < 10;++i)
            fromRight[i][n+1] = n+1;
        for(int i = 1; i <= n;++i){
            int val = vals[i-1]-'0';
            fromLeft[val][i] = i;
            nums[val].push_back(i);
            for(int j = 0;j < 10;++j){
                if(j == val) continue;
                fromLeft[j][i] = fromLeft[j][i-1];
                if(j)
                    fromLeft[j][i] = max(fromLeft[j-1][i],fromLeft[j][i]);
            }
        }
        for(int i = n; i >= 1; --i){
            int val = vals[i-1]-'0';
            fromRight[val][i] = i;
            for(int j = 0; j < 10;++j){
                if(j == val) continue;
                fromRight[j][i] = fromRight[j][i+1];
                if(j)
                    fromRight[j][i] = min(fromRight[j-1][i],fromRight[j][i]);
            }
        }
        for(int i = 1; i <= n;++i){
            for(int j = 1; j < 10;++j){
                int from = lower_bound(nums[j].begin(),nums[j].end(),i)-nums[j].begin();
                if(from == nums[j].size()) continue;
                from = nums[j][from];
                if(fromLeft[j-1][from] >= i)
                    continue;
                int to = fromRight[j-1][from];
                ans += j*(to-from);
                if(ans >= MOD)
                    ans -= MOD;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
