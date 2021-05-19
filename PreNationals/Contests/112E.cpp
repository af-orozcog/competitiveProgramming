#include<bits/stdc++.h>
using namespace std;

const int N = 7;
const int M = 1<<6;

int dp[N][M];

int INF = 50000;

int sum(int va1, int va2, int sz){
    vector<vector<int>> see(2);
    for(int i = 0; i < sz;++i){
        if(va1&1)see[0].push_back(1);
        else see[0].push_back(0);
        va1 >>= 1;
    }
    for(int i = 0; i < sz;++i){
        if(va2&1) see[1].push_back(1);
        else see[0].push_back(0);
        va2 >>= 1;
    }
    bool posi = 1;
    int s = 0;
    for(int i = 0; i < 2 && posi;++i){
        for(int j = 0; j < sz && posi;++j){
            posi = (j > 0 && see[i][j-1]) || (j != sz-1 && see[i][j+1]) || (see[i][j]) || (see[(i+1)&1][j]);
            if(i != 0 && see[i][j]) ++s;
        }
    }
    if(!posi) return INF;
    return s;
}


int main(){
    for(int i = 0; i < N;++i){
        for(int j = 0; j < M;++j){
            dp[i][j][k] = INF;
        }
    }
    int n,m;
    scanf(" %d %d",&n,&m);
    if(n > m) swap(n,m);
    for(int i = 0; i < (1<<m);++i){
        dp[0][i] = sum()
    }


    int ans = INT_MAX;
    for(int i = 0; i  < (1<<m);++i)
        ans = min(dp[n-1][i],ans);

    printf("%d\n",ans);
    return 0;
}
