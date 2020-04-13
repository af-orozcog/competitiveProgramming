#include<bits/stdc++.h>
using namespace std;

int dp[10][10][10];
int ans[10][10];
void pre(){
    for(int i = 0; i < 10;++i){
        for(int j = 0; j < 10;++j){
            queue<pair<int,int>> q;
            q.push({0,0});
            while(q.size()){
                pair<int,int> p = q.front();q.pop();
                int ne1 = p.first+i,ne2 = p.first+j;
                if(ne1 > 9) ne1 -= 10;
                if(ne2 > 9) ne2 -= 10;
                if(dp[i][j][ne1] == 1000000000){
                    dp[i][j][ne1] = p.second+1;
                    q.push({ne1,dp[i][j][ne1]});
                }
                if(dp[i][j][ne2] == 1000000000){
                    dp[i][j][ne2] = p.second+1;
                    q.push({ne2,dp[i][j][ne2]});
                }
            }
        }
    }
}

int main(){
    for(int i = 0; i < 10;++i)
        for(int j = 0; j < 10;++j)
            for(int k = 0; k < 10;++k) dp[i][j][k] = 1000000000;
    pre();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string see;
    cin >> see;
    for(int i = 0; i < 10;++i){
        for(int j = 0; j < 10;++j){
            for(int k = 0; k < (int)see.size()-1;++k){
                int to1 = (see[k+1]-'0');
                int to2 = (see[k]-'0');
                to1 -= to2;
                if(to1 < 0) to1 += 10;
                int val = dp[i][j][to1];
                if(dp[i][j][to1] != 1000000000)
                    ans[i][j] += dp[i][j][to1]-1;
                else{
                    ans[i][j] = -1; break;
                }
            }
        }
    }
    for(int i = 0; i < 10;++i){
        for(int j = 0; j < 10;++j) printf("%d ",ans[i][j]);
        puts("");
    }
    return 0;
}
