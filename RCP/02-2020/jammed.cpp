#include<bits/stdc++.h>
#define ld long double
using namespace std;

int n;
int order[102];
ld dp[102][102];
int m;
ld imp;

ld solve(int i, int l,map<int,vector<int>> &fr){
    if(i == n) return 0.0;
    if(dp[i][l] != -1.0) return dp[i][l];
    dp[i][l] = 1000000000;
    for(int j = 0; j < fr[order[i]].size();++j){
        int see = abs(l-fr[order[i]][j]);
        ld ang = (ld)abs(l-fr[order[i]][j])*imp;
        ang = min(ang,360.0-ang);
        ld toUse = ang/(ld)2.0;
        toUse = toUse * (ld) 3.141592653589793 / (ld) 180.0;
        ld dist = (ld)2.0*((ld)sin(toUse));
        dp[i][l] = min(dp[i][l],dist+solve(i+1,fr[order[i]][j],fr));
    }
    return dp[i][l];
}

int main(){
    scanf(" %d",&n);
    for(int i = 0; i < 102;++i){
        for(int j = 0; j < 102;++j)
            dp[i][j] = -1.0;
    }
    for(int i = 0; i < n;++i) scanf(" %d",&order[i]);
    scanf(" %d",&m);
    map<int,vector<int>> fr;
    for(int i = 0; i < m;++i){
        int va; scanf(" %d",&va);
        fr[va].push_back(i);
    }
    imp = 360.0/(ld)m;
    ld ans = 1000000000;
    for(int i = 0; i < fr[order[0]].size();++i)
        ans = min(ans,solve(1,fr[order[0]][i],fr)+(ld)1);
    cout << fixed << setprecision(7) << ans << "\n";
    return 0;
}
