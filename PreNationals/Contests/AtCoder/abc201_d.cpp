#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;

int dp[2000][2000];
int h,w;

vector<pi> posi(int x, int y){
    vector<pi> ans = {{x+1,y},{x,y+1}};
    return ans;
}

int go(int x, int y){
    vector<pi> see = posi(x,y);
    int ans = INT_MIN;
    int out = 0;
    for(auto &use: see){
        if(use.first < h && use.second < w)
            ans = max(ans,dp[use.first][use.second]);
        else ++out;
    }
    if(out == 2) return 0;
    return ans;
}

int main(){
    scanf(" %d %d",&h,&w);
    char mp[h][w];
    for(int i = 0; i < h;++i){
        for(int j = 0; j < w;++j){
            scanf(" %c",&mp[i][j]);
            dp[i][j] = dp[i][j] = INT_MIN;
        }
    }
    if(h == 1 && w == 1){
        puts("Draw");
        return 0;
    }

    dp[h-1][w-1] = 0;
    for(int i = h-1; i > -1;--i){
        for(int j = w-1; j > -1;--j){
                if(i != h-1)
                    dp[i][j] = max(dp[i][j], (mp[i+1][j] == '+'? 1:-1) + go(i+1,j));
                if(j != w-1)
                    dp[i][j] = max(dp[i][j],(mp[i][j+1] == '+'?1:-1) + go(i,j+1));
        }
    }
    int win = 0;
    int draw = 0;
    int see = dp[0][0];
    if(h > 1 && see > dp[1][0]) ++win;
    if(h > 1 && see == dp[1][0]) ++draw;
    if(w > 1 && see > dp[0][1]) ++win;
    if(w > 1 && see == dp[0][1]) ++draw;
    if(win)
        puts("Takahashi");
    else if(draw == 2) puts("Draw");
    else puts("Aoki");
    return 0;
}
