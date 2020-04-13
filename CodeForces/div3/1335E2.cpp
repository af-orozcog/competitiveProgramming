#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int acum[201][n];
        int nums[n];
        memset(acum,0,sizeof(acum));
        for(int i = 0; i < n;++i){
            int va;scanf(" %d",&va);
            ++acum[va][i];
            nums[i] = va;
            if(i > 0){
                for(int j = 1; j < 201;++j)
                    acum[j][i] += acum[j][i-1];
            }
        }
        int show = 0;
        for(int i = 0; i < 201;++i)
            show = max(show,acum[i][n-1]);
        map<int,int> fr;
        for(int i = n-1; i > 0;--i){
            ++fr[nums[i]];
            int tar = fr[nums[i]];
            int lo = 0,hi = i-1, ans = -1;
            while(lo <= hi){
                int mid = (lo+hi)>>1;
                if(acum[nums[i]][mid] == tar && (mid == 0 || acum[nums[i]][mid-1] != tar)){ans= mid;break;}
                else if(acum[nums[i]][mid] < tar) lo = mid+1;
                else hi = mid-1;
            }
            if(ans == -1 || ans == i || i == ans -1) continue;
            int ma = 0;
            for(int k = 1; k < 201;++k){
                    int va = acum[k][i-1];
                    va -= acum[k][ans];
                    ma = max(va,ma);
            }
            //cout << ma+(tar<<1) << "\n";
            show = max(show,ma+(tar<<1));
        }
        printf("%d\n",show);
    }
    return 0;
}
