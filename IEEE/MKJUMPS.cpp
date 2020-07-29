#include<bits/stdc++.h>
using namespace std;

pair<int,int> nums[11];
int n;

int movesX[] = {-2,-2,-1,-1,1,1,2,2};
int movesY[] = {-1,1,-2,2,-2,2,-1,1};
int ma = 0;

void dfs(int x, int y, int co, set<pair<int,int>> &seen){
    pair<int,int> neDad = {x,y};
    if(neDad.first < 0 || neDad.first >= n) return;
    if(neDad.second < nums[neDad.first].first || neDad.second > nums[neDad.first].second) return;
    seen.insert(neDad);
    for(int i = 0; i < 8;++i){
        if(!seen.count({x+movesX[i],y+movesY[i]}))
            dfs(x+movesX[i],y+movesY[i],co + 1,seen);
    }
    seen.erase(neDad);
    ma = max(ma,co+1);
}


int main(){
    int cas = 1;
    while(scanf(" %d",&n) && n){
        int total = 0;
        ma = 0;
        for(int i = 0; i < n;++i){
            scanf(" %d %d",&nums[i].first,&nums[i].second);
            total += nums[i].second;
            nums[i].second = nums[i].first+nums[i].second-1;
        }
        set<pair<int,int>> seen;
        dfs(0,nums[0].first,0,seen);
        if(total-ma == 1)
            printf("Case %d, %d square can not be reached.\n",cas++,total-ma);
        else
            printf("Case %d, %d squares can not be reached.\n",cas++,total-ma);
    }
    return 0;
}
