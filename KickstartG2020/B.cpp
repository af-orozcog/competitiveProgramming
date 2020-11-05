#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll path(int x, int y, vector<vector<ll>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    ll ans = 0;
    while(x < n && y < m){
        ans += matrix[x][y];
        ++x,++y;
    }
    return ans;
}


int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        vector<vector<ll>> matrix(n,vector<ll>(n));
        for(int i = 0; i < n;++i)
            for(int j = 0; j < n;++j)
                scanf(" %lld",&matrix[i][j]);
        ll ans = 0;
        for(int i = 0; i < n;++i){
            ans = max(ans,path(i,0,matrix));
            if(i)
                ans = max(ans,path(0,i,matrix));
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
