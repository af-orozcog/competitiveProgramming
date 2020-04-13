#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[27][n];
        memset(nums,0,sizeof(nums));
        for(int i = 0; i < n;++i){
            int va;scanf(" %d",&va);
            ++nums[va][i];
            if(i > 0){
                for(int j = 0; j < 27;++j)
                    nums[j][i] += nums[j][i-1];
            }
        }
        int ans = 0;
        for(int i = 0; i < 27;++i){
            ans = max(ans,nums[i][n-1]);
            //cout << nums[i][n-1] << "\n";
        }
        for(int i = 1; i < n-1;++i){
            for(int j = i; j < n-1;++j){
                int ma = 0;
                for(int k = 0; k < 27;++k){
                    int va = nums[k][j];
                    va -= nums[k][i-1];
                    ma = max(va,ma);
                }
                int ma2 = 0;
                for(int k = 0; k < 27;++k){
                    int be = nums[k][i-1];
                    int af = nums[k][n-1] - nums[k][j];
                    ma2 = max(ma2,min(be,af));
                }
                if(ma2 == 0)continue;
                ans = max(ans,ma+(ma2<<1));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
