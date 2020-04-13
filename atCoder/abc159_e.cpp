#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int dp[11][1001];

int sum(int x1,int y1,int x2,int y2){
    int ans = dp[x2][y2];
    if(y1 > 0) ans -= dp[x2][y1-1];
    if(x1 > 0) ans -= dp[x1-1][y2];
    if(y1 > 0 && x1 > 0) ans += dp[x1-1][y1-1];
    return ans;
}
int h,w,k;

int howMany(vector<int> &lines){
    int last = w-1;
    int ans = 0;
    for(int j = last; j > -1;--j){
        int su = sum(0,j,lines[0],last);
        su = max(sum(lines.back()+1,j,h-1,last),su);
        for(int i = 0; i < lines.size()-1;++i)
            su = max(sum(lines[i]+1,j,lines[i+1],last),su);
        if(su > k){
            if(last == j)return 100000000;
            last = j;
            ++j;
            ++ans;
        }
    }
    return ans;
}

int main(){
    scanf(" %d %d %d",&h,&w,&k);
    int matrix[h][w];
    for(int i = 0; i < h;++i){
        char temp;
        for(int j = 0; j < w;++j){
            scanf(" %c",&temp);
            if(temp == '1')
                matrix[i][j] = 1;
            else matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < w;++i){
        for(int j = 0; j < h;++j){
            dp[j][i] = matrix[j][i];
            if(i > 0) dp[j][i] += dp[j][i-1];
            if(j > 0) dp[j][i] += dp[j-1][i];
            if(i > 0 && j > 0) dp[j][i] -= dp[j-1][i-1];
        }
    }
    if(dp[h-1][w-1] <= k){
        puts("0");
        return 0;
    }
    int ans = 1000000;
    for(int i = 1; i < (1<<(h-1));++i){
        int co = i;
        int j = 0;
        vector<int> send;
        while(co){
            if(co&1)send.push_back(j);
            co = co >> 1;
            ++j;
        }
        ans = min(ans,howMany(send)+(int)send.size());
    }
    printf("%d\n",ans);
    return 0;
}
