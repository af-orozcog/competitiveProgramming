#include<bits/stdc++.h>
using namespace std;

int lg2[10000];
int st[1000][11][1000][11];
int dp[1000][1000];

int query(int x1,int y1,int x2, int y2){
    int imp1 = lg2[x2-x1+1];
    int imp2 = lg2[y2-y1+1];
    return max(max(st[x1][imp1][y1][imp2],st[x2-(1<<imp1)+1][imp1][y1][imp2]),
               max(st[x1][imp1][y2-(1<<imp2)+1][imp2],st[x2-(1<<imp1)+1][imp1][y2-(1<<imp2)+1][imp2]));
}

int main(){
    lg2[1] = 0;
    for(int i = 2; i < 10000;++i)
        lg2[i] = lg2[i>>1] + 1;
    int n,m;
    scanf(" %d %d",&n,&m);
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j){
            int va;
            scanf(" %d",&va);
            if(va)
                dp[i][j] = min(min((i?dp[i-1][j]:0),(j?dp[i][j-1]:0)),(i && j?dp[i-1][j-1]:0)) + 1;
        }
    }
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j)
            st[i][0][j][0] = dp[i][j];

        for(int k = 1; k <= 10;++k){
            for(int j = 0; (j+(1<<k)) <= m;++j)
                st[i][0][j][k] = max(st[i][0][j][k-1],st[i][0][j+(1<<(k-1))][k-1]);
        }
    }

    for(int k1 = 1; k1 <= 10;++k1){
        for(int i = 0; (i+(1<<k1)) <= n;++i){
            for(int k2 = 0; k2 <= 10;++k2){
                for(int j = 0; (j+(1<<k2)) <= m;++j)
                    st[i][k1][j][k2] = max(st[i][k1-1][j][k2],st[i+(1<<(k1-1))][k1-1][j][k2]);
            }
        }
    }
    int x1,y1,x2,y2;
    int q;
    scanf(" %d",&q);
    while(q--){
        scanf(" %d %d %d %d",&x1,&y1,&x2,&y2);
        --x1,--y1,--x2,--y2;
        int lo = 1, hi = min(x2-x1+1,y2-y1+1), ans = 0;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            int val = query(x1+mid-1,y1+mid-1,x2,y2);
            if(val >= mid){
                ans = mid;
                lo = mid +1;
            }
            else hi = mid -1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
