#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    vector<vector<int>> dp11(n,vector<int> (m)),dp12(n,vector<int> (m)),dp21(n,vector<int> (m)),dp22(n,vector<int> (m));
    int ans = 0;
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j){
            int temp; scanf(" %d",&temp);
            dp11[i][j] = dp12[i][j] = dp21[i][j] = dp22[i][j] = temp;
        }
    }
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j){
            int ma = 0;
            if(i > 0) ma = max(dp11[i-1][j],ma);
            if(j > 0) ma = max(dp11[i][j-1],ma);
            dp11[i][j] += ma;
        }
    }
    for(int i = n-1; i > -1;--i){
        for(int j = m-1; j > -1;--j){
            int ma = 0;
            if(i < n-1) ma = max(dp12[i+1][j],ma);
            if(j < m-1) ma = max(dp12[i][j+1],ma);
            dp12[i][j] += ma;
        }
    }
    for(int i = n-1;i > -1;--i){
        for(int j = 0; j < m;++j){
            int ma = 0;
            if(i < n-1) ma = max(dp21[i+1][j],ma);
            if(j > 0) ma = max(dp21[i][j-1],ma);
            dp21[i][j] += ma;
        }
    }
    for(int i = 0; i < n;++i){
        for(int j = m-1; j > -1;--j){
            int ma = 0;
            if(i > 0) ma = max(dp22[i-1][j],ma);
            if(j < m-1) ma = max(dp22[i][j+1],ma);
            dp22[i][j] += ma;
        }
    }
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j){
            if(i == 0 || j == 0 || i == n-1 || j == m-1) continue;
            ans = max(ans,dp11[i-1][j] + dp12[i+1][j] + dp21[i][j-1] + dp22[i][j+1]);
            ans = max(ans,dp11[i][j-1] + dp12[i][j+1] + dp21[i-1][j] + dp22[i+1][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
